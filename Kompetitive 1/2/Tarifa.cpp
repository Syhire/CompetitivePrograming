#include <stdio.h>

int main()
{
    int x, n, sum = 0;
    scanf("%d %d", &x, &n);

    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);

        sum += x - input;
    }

    printf("%d", sum + x);

    return 0;
}