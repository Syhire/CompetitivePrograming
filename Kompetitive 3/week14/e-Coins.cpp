#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace std;

pair<int, int> coords[45];
int dp[310][310];

int m, S;
int eModulus;

int solve(int x, int y)
{
    int mod = x * x + y * y;

    if (mod == eModulus)
        return 0;

    if (mod > eModulus)
        return 90010; // 300 * 300 + 10

    if (dp[x][y] != -1)
        return dp[x][y];

    int res = 90010;

    for (int i = 0; i < m; i++)
    {
        res = min(res, 1 + solve(x + coords[i].first, y + coords[i].second));
    }

    // printf("%d\n", res);
    dp[x][y] = res;
    return res;
}

int main()
{
    int loop;
    scanf("%d\n", &loop);

    while (loop--)
    {
        scanf("%d %d\n", &m, &S);
        eModulus = S * S;

        int input1, input2;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d\n", &input1, &input2);
            coords[i] = make_pair(input1, input2);
        }

        memset(dp, -1, sizeof(int) * 310 * 310);
        int res = solve(0, 0);
        // printf("a");
        if (res == 90010)
            printf("not possible\n");
        else
            printf("%d\n", res);
    }
}