#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, d;
int squares[10010];
// unsigned long long dp[10000010];
bool visited[10010];
int manySq;

unsigned long long solve(int square)
{
    if (square == 0)
        return 0;
    // if (dp[square] != -1)
    //     return dp[square];

    // printf("-- %d\n", square);

    unsigned long long sum = ULLONG_MAX;

    for (int i = 1; i <= square; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[j])
                continue;

            if ((manySq == 1 && i != square) || manySq <= 0)
                break;

            // printf("- %d-%d %d\n", square, i, squares[j]);

            visited[j] = true;
            manySq--;
            unsigned long long temp = (i * i * squares[j]);
            unsigned long long temp2 = solve(square - i);
            manySq++;
            if (temp2 != ULLONG_MAX)
                sum = min(sum, temp + temp2);
            visited[j] = false;

            // printf("-- %d %d %d %llu + %llu\n", square, i, squares[j], temp, temp2);
        }
    }

    // printf("# %d: %llu\n", square, sum);

    // if (sum == ULLONG_MAX)
    //     sum = 0;

    return sum;
}

int main()
{
    int countCase;
    scanf("%d\n", &countCase);
    while (countCase--)
    {
        scanf("%d %d\n", &n, &d);

        for (int i = 0; i < n; i++)
            scanf("%d\n", &squares[i]);

        manySq = n;

        printf("%llu\n", solve(d));
    }
}