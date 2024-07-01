#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[200010];
int t, n, input;

bool comparefn(int a, int b)
{
    if (a ^ b < 4)
        return a < b;
    return false;
}

int main()
{
    scanf("%d\n", &t);

    while (t--)
    {
        scanf("%d\n", &n);
        for (int i = 0; i < n; i++)
            scanf("%d\n", &arr[i]);

        sort(arr, arr + n, comparefn);
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);

        printf("\n");
    }
}