#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int n, m;
int map[15][105];
int dp[15][105];
int path[15][105];

int solve(int row, int col)
{
    if (row == 0 && col == 0)
        return 0;
    if (row == 0)
        return INT_MIN;

    if (dp[row][col] != -1)
        return dp[row][col];

    int res = INT_MIN;

    // take top
    res = min(res, map[row - 1][col - 1] + solve(row - 1, col - 1));
    // take mid
    res = min(res, map[row][col - 1] + solve(row, col - 1));
    // take bot
    res = min(res, map[row + 1][col - 1] + solve(row + 1, col - 1));

    return dp[row][col] = res;
}

int main()
{
    while (scanf("%d %d\n", &n, &m) != EOF)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d\n", &map[i][j]);

        memset(dp, -1, sizeof(int) * 15 * 105);

        printf("%d\n", solve(n - 1, m - 1));
    }
}