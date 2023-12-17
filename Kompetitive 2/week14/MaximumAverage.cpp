#include <stdio.h>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;

int n, a, b;
int arr[510];

double findMaxSubArray(int len)
{
    int res = numeric_limits<int>::min();

    res = max(res, arr[len - 1]);

    for (int i = len; i < n; i++)
        res = max(res, arr[i] - arr[i - len]);

    return (double)res / len;
}

int main()
{
    scanf("%d %d %d\n", &n, &a, &b);
    arr[-1] = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &arr[i]);
        arr[i] += arr[i - 1];
    }

    double maxValue = findMaxSubArray(a);

    for (int i = a + 1; i <= b; i++)
        maxValue = max(maxValue, findMaxSubArray(i));

    printf("%.3lf\n", maxValue);
}