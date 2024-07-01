#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);

    int x, y;
    while (n--)
    {
        scanf("%d %d\n", &x, &y);
        printf("%d %d\n", min(x, y), max(x, y));
    }

    return 0;
}
