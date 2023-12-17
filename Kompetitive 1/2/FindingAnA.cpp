#include <stdio.h>

int main()
{
    char c;
    bool isThereA = false;
    while (scanf("%c", &c) != EOF)
    {
        if (c == 'a')
            isThereA = true;

        if (isThereA)
            printf("%c", c);
    }
}