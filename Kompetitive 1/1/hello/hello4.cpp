#include <stdio.h>

int main()
{
    int n;

    while (scanf("%d ", &n) != EOF)
    {
        int a;
        scanf("%d\n", &a);

        printf("%d\n", (n + a));
    };

    return 0;
}