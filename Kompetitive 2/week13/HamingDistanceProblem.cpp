#include <stdio.h>
#include <string.h>
using namespace std;

int n, h;
int res[20];
int sum;

void bString(int len)
{
    if (len == n)
    {
        if (sum == h)
        {
            for (int i = 0; i < n; i++)
                printf("%d", res[i]);
            printf("\n");
        }
        return;
    }
    else
    {
        res[len] = 0;
        if (sum <= h)
            bString(len + 1);

        res[len] = 1;
        sum++;
        if (sum <= h)
            bString(len + 1);
        sum--;
    }
}

int main()
{
    int countCase;
    scanf("%d\n", &countCase);

    while (countCase--)
    {
        memset(res, 0, sizeof(int) * 20);
        sum = 0;
        scanf("\n%d %d\n", &n, &h);
        bString(0);
        if (countCase)
            printf("\n");
    }
}