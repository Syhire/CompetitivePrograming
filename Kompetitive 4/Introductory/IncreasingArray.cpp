#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    unsigned long long n, a = 0, b, sum = 0;
    scanf("%llu\n", &n);

    while (n--)
    {
        scanf("%llu\n", &b);
        a = max(a, b);
        sum += a - b;
        // printf("%llu %llu -> %llu\n", a, b, sum);
    }

    printf("%llu\n", sum);
}