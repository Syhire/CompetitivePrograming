#include <stdio.h>
#include <string.h>
// work
int main()
{
    char a;
    int b;

    bool tied = false;
    char arr[201] = {'\0'};

    scanf("%[^\n]\n", arr);

    int A = 0, B = 0;
    int i, length = strlen(arr);

    for (i = 0; i < length; i += 2)
    {
        if (arr[i] == 'A')
            A += arr[i + 1] - '0';
        else
            B += arr[i + 1] - '0';

        if (A == 10 && B == 10)
            tied = true;
        if (A > 10 || B > 10)
        {
            if (A - B >= 1 && !tied)
            {
                printf("A\n");
                break;
            }
            else if (B - A >= 1 && !tied)
            {
                printf("B\n");
                break;
            }
            else if (A - B >= 2 && tied)
            {
                printf("A\n");
                break;
            }
            else if (B - A >= 2 && tied)
            {
                printf("B\n");
                break;
            }
        }
    }
}