#include <stdio.h>
#include <cmath>

int main()
{
    int n;
    int sum = 0;
    while (scanf("%d\n", &n))
    {
        if (n == -1)
            break;

        sum += n;
    };

    printf("%d", sum);

    return 0;
}