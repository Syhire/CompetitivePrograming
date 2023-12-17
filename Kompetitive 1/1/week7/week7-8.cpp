#include <stdio.h>
// work
int main()
{
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    int i, j;
    int sum = 0;

    for (i = 0; i < n; i++)
    {
        sum = m / (n - i);
        for (j = 0; j < sum; j++)
            printf("*");
        m -= sum;
        printf("\n");
    }
}