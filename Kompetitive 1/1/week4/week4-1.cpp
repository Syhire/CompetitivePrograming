#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int A = min(a, min(b, c));
    int C = max(a, max(b, c));
    int B = a + b + c - A - C;

    int n = 0;

    // 1: A, X, B, C

    n = A + C - B;

    if (n - A == B - n)
    {
        printf("%d", n);
        return 0;
    }

    // 2: A, B, X, C

    n = B - A + B;

    if (n - B == C - n)
    {
        printf("%d", n);
        return 0;
    }

    // 3: A, B, C, X

    n = B - A + C;

    if (n - C == B - A)
    {
        printf("%d", n);
        return 0;
    }

    return 0;
}