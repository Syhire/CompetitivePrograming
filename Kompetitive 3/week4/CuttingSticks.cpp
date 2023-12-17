#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int l;

int dp[60][60];
int stick[60];

int solve(int i, int j) // i sampai j
{
    // printf("%d %d\n", i, j);

    if (i + 1 == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int res = 100000;

    for (int m = i + 1; m < j; m++)
        res = min(res, solve(i, m) + solve(m, j) + stick[j] - stick[i]);

    return dp[i][j] = res;
}

int main()
{
    while (scanf("%d\n", &l) && l != 0)
    {
        scanf("%d\n", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d\n", &stick[i]);

        stick[0] = 0;
        stick[n + 1] = l;

        memset(dp, -1, sizeof(int) * 60 * 60);
        printf("The minimum cutting is %d.\n", solve(0, n + 1));
    }
}