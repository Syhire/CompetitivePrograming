#include <stdio.h>
#include <algorithm>

using namespace std;

int n;

int main()
{
    scanf("%d\n", &n);

    if (n == 1)
    {
        printf("1\n");
        return 0;
    }

    if (n <= 3)
    {
        printf("NO SOLUTION\n");
        return 0;
    }

    if (n & 1)
    {
        for (int i = 2; i + 2 < n - 2; i += 2)
        {
            printf("%d ", i);
        }

        printf("%d %d ", n - 1, n - 3);
        printf("%d", n);

        for (int i = n - 2; i >= 1; i -= 2)
        {
            printf(" %d", i);
        }
    }
    else
    {
        for (int i = 2; i + 2 <= n; i += 2)
        {
            printf("%d ", i);
        }

        printf("%d", n);
        printf(" %d %d", n - 3, n - 1);

        for (int i = n - 5; i >= 1; i -= 2)
        {
            printf(" %d", i);
        }
    }
}