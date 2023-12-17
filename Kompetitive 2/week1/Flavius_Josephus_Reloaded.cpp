#include <stdio.h>

long long N, a, b;

long long f(long long x)
{
    return (a * (x * x % N) % N + b) % N;
}

int main()
{

    while (scanf("%lu %lu %lu", &N, &a, &b) != 1 && N != 0)
    {
        long long tortoise = f(0);
        long long hare = f(f(0));

        while (tortoise != hare)
        {
            tortoise = f(tortoise);
            hare = f(f(hare));
        }

        int mu = 0;
        hare = 0;

        while (tortoise != hare)
        {
            tortoise = f(tortoise);
            hare = f(hare);
        }

        int lambda = 1;
        hare = f(tortoise);
        while (tortoise != hare)
        {
            hare = f(hare);
            lambda++;
        }

        printf("%d\n", N - lambda);
    }
}