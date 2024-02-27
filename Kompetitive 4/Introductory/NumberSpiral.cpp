#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    unsigned long long t, y, x;
    scanf("%llu\n", &t);

    while (t--)
    {
        scanf("%llu %llu\n", &y, &x);
        unsigned long long a = max(y, x);
        unsigned long long sN = a * a - (a - 1);
        unsigned long long diff = y - x;

        // printf("%d %d %d\n", sN, diff, a & 1);
        printf("%llu\n", sN + (diff * (a & 1 ? -1 : 1)));
    }
}