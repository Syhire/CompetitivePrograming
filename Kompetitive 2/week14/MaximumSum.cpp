#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int n, a, b;
int arr[510];

int findMaxSubArray(int len)
{
    int res = -10000;

    res = max(res, arr[len - 1]);

    for (int i = len; i < n; i++)
        res = max(res, arr[i] - arr[i - len]);

    return res;
}

int main()
{
    scanf("%d %d %d\n", &n, &a, &b);

    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &arr[i]);
        if (i != 0)
            arr[i] += arr[i - 1];
    }

    int maxValue = findMaxSubArray(a);

    for (int i = a + 1; i <= b; i++)
        maxValue = max(maxValue, findMaxSubArray(i));

    printf("%d\n", maxValue);
}