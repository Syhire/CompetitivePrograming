#include <stdio.h>

int main()
{
    unsigned long long n, input, tes, tes2;
    scanf("%llu\n", &n);

    tes = n / 2.0 * (2.0 + (n - 1.0));
    // printf("%llu\n", tes);

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%llu\n", &input);
        tes -= input;
        // printf("%llu, %llu\n", i, tes);
    }

    printf("%llu\n", tes);
}