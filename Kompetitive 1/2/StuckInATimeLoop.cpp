#include <stdio.h>

int main()
{
    int count, countIdx;

    scanf("%d", &count);

    for (countIdx = 0; countIdx < count; countIdx++)
    {
        printf("%d Abracadabra\n", countIdx + 1);
    }

    return 0;
}