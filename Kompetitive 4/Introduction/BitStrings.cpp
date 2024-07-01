#include <stdio.h>

int main() {
    int n;
    scanf("%d\n", &n);
    long long sum = 1;
    for (int i = 0; i < n; i++)
        sum = (sum * 2) % 1000000007;
    printf("%lld\n", sum);
}