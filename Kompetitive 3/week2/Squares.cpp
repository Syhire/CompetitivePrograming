#include <stdio.h>
#include <string.h>
using namespace std;

long long dp[10005];
long long squares[105];

long long dyP(int n)
{
    if (n <= 0)
        return -1;
    if (dp[n] != -1)
        return dp[n];

    // printf("-> %d\n", n);
    long long sum = 10000000;

    for (int i = 1; squares[i] < n; i++) // 1^2, ... , x^2 (x^2 < n)
    {
        long long take = dyP(n - squares[i]) + 1;
        // printf("--> %d - %d (%d) = %d\n", n, squares[i], n - squares[i], take);
        if (take != -1)
            if (take < sum)
                sum = take;
    }

    // printf("---> %d = %d\n", n, sum);
    dp[n] = sum;
    return sum;
}

int main()
{
    int testCase;
    scanf("%d\n", &testCase);
    memset(dp, -1, sizeof(long long) * 10005);

    dp[0] = -1;

    if (testCase > 0)
        for (int i = 1; i <= 100; i++)
        {
            // printf("a");
            squares[i] = i * i;
            dp[squares[i]] = 1;
        }

    int n;

    while (testCase--)
    {
        scanf("%d\n", &n);
        long long sum = dyP(n);
        printf("%lld\n", sum < 0 ? 0 : sum);
    }
}