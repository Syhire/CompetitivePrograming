#include <stdio.h>

using namespace std;

int t, n, m;

int main()
{
    scanf("%d\n", &t);

    while (t--)
    {
        scanf("%d %d\n", &n, &m);
        int more = m - n;
        if (m <= n && more % 2 == 0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}