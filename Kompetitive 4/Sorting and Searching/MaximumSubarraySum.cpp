#include <stdio.h>
#include <limits.h>
using namespace std;

int n;
long long input, maxNow = 0, maxAll = LLONG_MIN;

int main() {
    scanf("%d\n", &n);

    while (n--)
    {
        scanf("%lld\n", &input);
        maxNow += input;
        if (maxAll < maxNow) maxAll = maxNow;
        if (maxNow < 0) maxNow = 0;
    }

    printf("%lld\n", maxAll);
}