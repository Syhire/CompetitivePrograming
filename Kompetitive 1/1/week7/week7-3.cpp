#include <stdio.h>
// work
int main()
{
    int n, x, y;
    scanf("%d %d %d\n", &n, &x, &y);
    int i;

    int a;

    for (i = 0; i < n; i++)
    {
        scanf("%d\n", &a);

        printf("%d\n", a * y / x);
    }
}