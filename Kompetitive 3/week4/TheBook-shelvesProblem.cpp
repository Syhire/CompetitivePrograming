#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
double wShelf;
long long w;

long long dp[1010];
pair<long long, long long> book[1010]; // h , w

long long solve(int index)
{
    // printf("%d (%lf)\n", index, dp[index]);

    if (index <= 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    long long res = 1000000000;
    long long width = 0;
    long long height = 0;

    for (int i = 1; i <= index; i++)
    {
        height = max(book[index - i].first, height);
        width += book[index - i].second;

        // printf("%d - %d (%d): w: %lf h: %lf\n", index, i, index - i, width, height);

        if (width <= w)
        {
            long long temp = solve(index - i) + height;
            // printf("%lf\n", temp);
            res = min(temp, res);
        }
    }

    // printf("%lf\n", res);

    return dp[index] = res;
}

int main()
{
    while (scanf("%d %lf\n", &n, &wShelf) && n != 0 && wShelf != 0.0)
    {
        w = (long long)(10000 * wShelf);

        double h, wd;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf\n", &h, &wd);
            // printf("%lf %lf\n", h, w);
            book[i] = make_pair((long long)(h * 10000), (long long)(wd * 10000));
        }

        // for (int i = 0; i < n; i++)
        //     printf("%d: > h:%lld, w:%lld\n", i + 1, book[i].first, book[i].second);

        // for (int i = 0; i < n + 1; i++)
        //     dp[i] = -1.0;

        memset(dp, -1, sizeof(long long) * 1010);
        long long res = solve(n);
        printf("%lld.%04lld\n", res / 10000, res % 10000);
    }
}