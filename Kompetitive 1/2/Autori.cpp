#include <stdio.h>
#include <string.h>

int main()
{
    char charArr[110];
    scanf("%[^\n]", charArr);

    printf("%c", charArr[0]);
    for (int i = 0; i < strlen(charArr) - 1; i++)
    {
        if (charArr[i] == '-')
            printf("%c", charArr[i + 1]);
    }

    return 0;
}