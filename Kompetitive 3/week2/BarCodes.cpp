#include <stdio.h>
#include <string.h>
// #include <algorithm>
using namespace std;

long long dp[105][105];

long long dyP(int n, int k, int m)
{
    if (n <= 0 || k > n || (k == 1 && n > m))
        return -1;
    if (k == 1 || k == n)
        return 1;
    if (dp[n][k] != -1)
        return dp[n][k];

    // printf("-> %d %d\n", n, k);
    long long sum = 0;

    for (int i = 1; i <= m && n > i; i++)
    {
        long long take = dyP(n - i, k - 1, m);
        // printf("--> %d - %d (%d), %d - 1 (%d) = %d\n", n, i, n - i, k, k - 1, take);
        if (take != -1)
            sum += take;
    }

    dp[n][k] = sum;
    return sum;
}

int main()
{
    int n, k, m;

    while (scanf("%d %d %d\n", &n, &k, &m) != EOF)
    {
        memset(dp, -1, sizeof(long long) * 105 * 105);
        long long sum = dyP(n, k, m);
        printf("%lld\n", sum < 0 ? 0 : sum);
    }
}