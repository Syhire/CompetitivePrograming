#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int arr[100010];
int value[100010];

int dkt(int i)
{
    if (value[i] > 0)
        return value[i];

    int maxValue = 1;

    for (int j = 0; j < i; j++)
    {
        if (arr[i] % arr[j] == 0 || arr[j] % arr[i] == 0)
        {
            int temp = dkt(j) + 1;
            maxValue = max(maxValue, temp);
        }
    }

    value[i] = maxValue;

    return maxValue;
}

int main()
{
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
        scanf("%d\n", &arr[i]);

    int maxValue = 0;
    value[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int temp = dkt(i);
        if (temp > maxValue)
        {
            maxValue = temp;
        }
    }

    printf("%d\n", maxValue);
}