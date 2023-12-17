#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char a;

    while (scanf("%s\n", a) != EOF)
    {
        printf("%d\n", a);
        printf("test");
    };

    return 0;
}