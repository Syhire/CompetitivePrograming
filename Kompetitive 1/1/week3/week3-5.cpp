#include <cstdio>

int main()
{
    int n;

    scanf("%d", &n);

    int a = 0;

    int arr[101] = {0};

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &a);

        arr[a] = i + 2;
    }

    printf("1 ");

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != 0)
            printf("%d ", arr[i]);
    }
}
