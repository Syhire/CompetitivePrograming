#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int loop, i, j;

    scanf("%d\n", &loop);

    int n = 0;
    int arr[101];
    bool isInc;

    for (i = 0; i < loop; i++)
    {
        scanf("%d\n", &n);

        for (j = 0; j < n; j++)
            scanf("%d", &arr[j]);

        sort(arr, arr + n);

        isInc = true;

        for (j = 0; j < n - 1; j++)
            if (arr[j + 1] <= arr[j])
                isInc = false;

        if (isInc)
            printf("YES");
        else
            printf("NO");
        printf("\n");
    }
}