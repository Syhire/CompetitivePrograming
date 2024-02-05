#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;


long long dp[25][25];
int a, n;

long long solve(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    // printf("=> %d %d\n", i, j);

    long long res = -1;

    if (i >= j) {
        long long res1 = 0, res2 = 0;

        if (i != n)
            for (int k = i + 1; k <= n; k++)
                res1 = max(res1, solve(k, 1) + solve(k, j));
        
        if (j != 0)
            for (int k = 1; k < j; k++)
                res2 = max(res2, solve(i, k) + solve(n, k));
        
        res = res1 + res2;
    } else if (i < j) {
        for (int k = i; k < j; k++)
            res = max(res, solve(i, k) + solve(k + 1, j));
    }

    return dp[i][j] = res;
}

int main() {
    while (scanf("%d %d", &n, &a) != EOF)
    {
        memset(dp, -1, sizeof(long long) * 25 * 25);
        dp[n][1] = a;
        printf("%lld\n", solve(1, n));
    }
}