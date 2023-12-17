#include <stdio.h>

int main()
{
    int n;
    char str[110];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        if (i % 2 == 0)
            printf("%s", str);
    }

    return 0;
}