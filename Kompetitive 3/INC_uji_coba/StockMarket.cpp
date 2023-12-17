#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, p0, x;
long long trend = 0, maxTrend = LLONG_MIN, minTrend = LLONG_MAX;
int day[100010] = {0};

int main()
{
    scanf("%d %d %d\n", &n, &p0, &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &day[i]);
        trend += day[i];
        maxTrend = max(maxTrend, trend);
        minTrend = min(minTrend, trend);
    }

    int lowDay = -1;
    int price = -1;

    if (p0 >= x)
    {
        price = p0;
        lowDay = 0;
    }

    int sum = p0;
    int i = 0;

    // printf("## %d %d\n", maxTrend, minTrend);

    for (; true; i++)
    {
        if (trend >= 0 && sum > x)
        { // upward
            if (sum + maxTrend > x && sum + minTrend > x)
                break;
        }
        else if (sum < x) // downward
            if (sum + maxTrend < x && sum + minTrend < x)
                break;

        sum = sum + trend;
        // printf("#%d, %d (%d, %d)\n", sum, sum + trend, sum + maxTrend, sum + minTrend);
    }

    i -= 2;
    sum -= trend * 2;

    // printf("start: %d, sum: %d\n", i * n + 1, sum);

    for (int j = 0; j < n * 2; j++)
    {
        sum += day[j % n];
        // printf("day: %d = %d (%d)\n", n * i + j + 1, sum, price); // day

        if (price > sum && sum >= x)
        {
            price = sum;
            lowDay = n * i + j + 1;
        }
    }

    printf("%d\n", price);
}