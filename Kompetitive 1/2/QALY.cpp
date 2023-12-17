#include <stdio.h>
using namespace std;

int main()
{
    int n, i;

    scanf("%d", &n);

    double q, y;

    double sum;

    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &q, &y);

        sum += q * y;
    }

    printf("%.3lf", sum);
}