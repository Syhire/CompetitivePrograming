#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

double dp[105];                   // barang
vector<pair<int, double> > prices; // count, price

double dpAlgo(int n)
{
    // if (n < 0) return -1.0;
    if (n <= 0)
        return 0.0;
    if (dp[n] != -1.0)
        return dp[n];

    // printf("-> %d\n", n);

    double res = 1000000.0;

    for (int i = 0; i < prices.size(); i++)
    {
        double take = dpAlgo(n - prices[i].first) + prices[i].second;
        // printf("--> %d - %d (%d) = %.2lf\n", n, prices[i].first, n - prices[i].first, take);
        if (take != -1.0)
            if (take < res)
                res = take;
    }

    // printf("---> %d = %lf\n", n, res);

    dp[n] = res;
    return res;
}

int main()
{
    double price;
    int cPromo, testCase = 1, count;

    while (scanf("%lf %d\n", &price, &cPromo) != EOF)
    {
        printf("Case %d:\n", testCase++);
        prices.clear();
        prices.push_back(make_pair(1, price));
        // get promo
        while (cPromo--)
        {
            scanf("%d %lf\n", &count, &price);
            prices.push_back(make_pair(count, price));
        }

        int n;
        char inputs[1010];
        fgets(inputs, 1000, stdin);

        char *input;
        input = strtok(inputs, " \n");

        for (int i = 0; i < 105; i++)
            dp[i] = -1.0;

        while (input != NULL)
        {
            sscanf(input, "%d\n", &n);
            double res = dpAlgo(n);
            printf("Buy %d for $%.2lf\n", n, res);
            input = strtok(NULL, " \n");
        }
    }
}