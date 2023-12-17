#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    int i;

    long long A = 1, B = 0;

    for (i = 0; i < n; i++)
    {
        long long temp = A;
        A = B;
        B += temp;
    }

    printf("%lld %lld\n", A, B);
}