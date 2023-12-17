#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int a, i;

    scanf("%d %d", &a, &i);

    for (double n = 1; true; n++)
    {
        if (ceil(n / (double)a) == (double)i)
        {
            printf("%d", (int)n);
            break;
        }
    }

    return 0;
}