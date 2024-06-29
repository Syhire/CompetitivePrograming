#include <stdio.h>

using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);
    for (long long i = 1; i <= n; i++)
    {
        printf("%lld\n", (i * i) * (i * i - 1) / 2 - 4 * (i - 2) * (i - 1));
    }
}