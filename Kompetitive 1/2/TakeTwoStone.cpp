#include <stdio.h>

int main()
{
    unsigned long n;
    scanf("%lu", &n);

    printf("%s", n % 2 == 1 ? "Alice" : "Bob");
}