#include <stdio.h>

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);
    char str[1000];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
    }

    printf("%d", p);
}