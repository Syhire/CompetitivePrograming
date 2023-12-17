#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int N, P0, X, trend = 0;
    int day[100005] = {0};
    int price[100005] = {0};
    scanf("%d %d %d\n", &N, &P0, &X);
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &day[i]);
        trend += day[i];
    }
    int result = INT_MAX;
    for (int i = 0; i <= N; i++)
    {
        if (i == 0)
        {
            price[i] = P0;
        }
        else
        {
            price[i] = price[i - 1] + day[i - 1];
        }
        if (price[i] >= X)
        {
            result = min(result, price[i]);
        }
    }
    if (trend >= 0)
    {
        int count = 0;
        int i = N + 1;
        while (count < N)
        {
            price[i] = price[i - 1] + day[(i - 1) % N];
            if (price[i] >= X)
            {
                result = min(result, price[i]);
            }
            if (result < price[i])
            {
                count++;
            }
            else
            {
                count = 0;
            }
            i++;
        }
    }
    else
    {
        int count = 0;
        int i = N + 1;
        while (count < N)
        {
            price[i] = price[i - 1] + day[(i - 1) % N];
            if (price[i] >= X)
            {
                result = min(result, price[i]);
            }
            if (price[i] < X)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            i++;
        }
    }
    if (result == INT_MAX)
    {
        printf("-1");
    }
    else
    {
        printf("%d", result);
    }
}