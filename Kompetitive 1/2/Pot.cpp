#include <stdio.h>
#include <math.h>

int main()
{
    int n;

    scanf("%d", &n);
    int num;

    long sum = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        sum += (long)pow((double)(num / 10), (double)(num % 10));
    }

    printf("%ld", sum);
}