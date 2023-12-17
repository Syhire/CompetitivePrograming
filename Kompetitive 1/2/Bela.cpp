#include <stdio.h>

int domNumValue(char inputChar);
int nondomNumValue(char inputChar);

int main()
{
    char domChar;
    int n;

    scanf("%d %c\n", &n, &domChar);

    char inpChar, inpDom;
    int sum = 0;
    for (int i = 0; i < n * 4; i++)
    {
        scanf("%c%c\n", &inpChar, &inpDom);
        sum += inpDom == domChar ? domNumValue(inpChar) : nondomNumValue(inpChar);
    }

    printf("%d\n", sum);
    return 0;
}

int domNumValue(char inputChar)
{
    switch (inputChar)
    {
    case 'A':
        return 11;
    case 'K':
        return 4;
    case 'Q':
        return 3;
    case 'J':
        return 20;
    case 'T':
        return 10;
    case '9':
        return 14;
    default:
        return 0;
    }
}

int nondomNumValue(char inputChar)
{
    switch (inputChar)
    {
    case 'A':
        return 11;
    case 'K':
        return 4;
    case 'Q':
        return 3;
    case 'J':
        return 2;
    case 'T':
        return 10;
    default:
        return 0;
    }
}