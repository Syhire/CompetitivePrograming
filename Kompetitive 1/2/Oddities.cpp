#include <stdio.h>

int main()
{
    int count, countIdx;
    int n;

    scanf("%d", &count);

    for (countIdx = 0; countIdx < count; countIdx++)
    {
        scanf("%d", &n);

        printf("%d is %s\n", n, (n % 2 == 0 ? "even" : "odd"));
    }

    return 0;
}