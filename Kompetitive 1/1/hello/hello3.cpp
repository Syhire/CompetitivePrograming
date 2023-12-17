#include <stdio.h>

int main()
{
    int n;

    while (scanf("%d ", &n))
    {
        if (n == 0)
            break;

        int a;
        scanf("%d\n", &a);

        printf("%d\n", (n + a));
    };

    return 0;
}