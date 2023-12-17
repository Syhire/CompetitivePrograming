#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100];

    while (scanf("%s\n", str) != EOF)
    {

        for (int i = 0; i < strlen(str); i++)
        {
            str[i] = toupper(str[i]);
        }

        printf("%s\n", str);
    };

    return 0;
}