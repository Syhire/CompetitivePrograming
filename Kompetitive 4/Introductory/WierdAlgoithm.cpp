#include <stdio.h>

int main()
{
    unsigned long long n;
    scanf("%llu\n", &n);
    printf("%llu", n);

    while (n != 1)
    {
        if (n & 1) // ganjil
            n = n * 3 + 1;
        else // genap
            n /= 2;

        printf(" %llu", n);
    }
}