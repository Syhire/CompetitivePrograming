#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <float.h>
using namespace std;

int n;
double wShelf;

double dp[1010];
pair<double, double> book[1010]; // h , w

double solve(int index)
{
    // printf("%d (%lf)\n", index, dp[index]);

    if (index <= 0)
        return 0.0;
    if (dp[index] != -1.0)
        return dp[index];

    double res = DBL_MAX;
    double width = 0.0;
    double height = 0.0;

    for (int i = 1; i <= index; i++)
    {
        height = max(book[index - i].first, height);
        width += book[index - i].second;

        // printf("%d - %d (%d): w: %lf h: %lf\n", index, i, index - i, width, height);

        if (width <= wShelf)
        {
            double temp = solve(index - i) + height;
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
        double h, w;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf\n", &h, &w);
            book[i] = make_pair(h, w);
        }

        // for (int i = 0; i < n; i++)
        //     printf("%d: > h:%.4lf, w:%.4lf\n", i + 1, book[i].first, book[i].second);

        for (int i = 0; i < n + 1; i++)
            dp[i] = -1.0;

        printf("%.4lf\n", solve(n));
    }
}