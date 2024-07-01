#include <stdio.h>
#include <math.h>
using namespace std;

int n, a, b, c, d, temp;

int main()
{
    scanf("%d\n", &n);
    while (n--)
    {
        scanf("%d %d %d %d\n", &a, &b, &c, &d);
        temp = a;
        a = 1;
        b = (12 + b - temp) % 12 + 1;
        c = (12 + c - temp) % 12 + 1;
        d = (12 + d - temp) % 12 + 1;

        // printf("%d %d %d %d\n", a, b, c, d);
        int A = abs(a - c), B = abs(a - b), C = abs(a - d);
        if ((A > B && B > C) || (A < B && B < C))
            printf("YES\n");
        else
            printf("NO\n");
    }
}