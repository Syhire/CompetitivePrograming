#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int n, k;
int arr[100010];
int value[100010];
int parent[100010];

int dkt(int i)
{
    int max = value[i];
    parent[i] = i;

    for (int j = 0; j < i; j++)
    {
        if (abs(arr[i] - arr[j]) >= k)
        {
            int temp = value[j] + value[i];

            if (temp > max)
            {
                max = temp;
                parent[i] = j;
            }
        }
    }

    value[i] = max;

    return max;
}

int main()
{
    scanf("%d %d\n", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d %d\n", &arr[i], &value[i]);

    int max = 0;
    int maxIdx = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = dkt(i);
        if (temp > max)
        {
            max = temp;
            maxIdx = i;
        }
    }

    printf("%d\n", max);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", parent[i]);
    // }

    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", value[i]);
    // }
    // printf("\n");
}