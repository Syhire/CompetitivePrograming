#include <stdio.h>

int main()
{
    char str[100];

    fgets(str, 100, stdin);
    printf("%s", str);

    return 0;
}