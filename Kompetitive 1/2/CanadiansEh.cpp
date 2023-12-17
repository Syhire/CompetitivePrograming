#include <stdio.h>
#include <string.h>

int main()
{
    char charArr[110];
    scanf("%[^\n]", charArr);

    int len = strlen(charArr);

    if (charArr[len - 3] == 'e' && charArr[len - 2] == 'h' && charArr[len - 1] == '?')
    {
        printf("Canadian!");
        return 0;
    }

    printf("Imposter!");

    return 0;
}