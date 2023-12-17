#include <stdio.h>
#include <cstring>
// work
int main()
{
    char str[81] = {'\0'};
    int sum = 0;

    scanf("%[^\n]\n", str);

    for (int i = 0; i < 80; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'u' || str[i] == 'o' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'U' || str[i] == 'O')
            sum++;
    }

    printf("%d", sum);
}