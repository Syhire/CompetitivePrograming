#include <stdio.h>
#include <math.h>
using namespace std;

int t;
long long x;
bool arr[35];

int main()
{
    scanf("%d\n", &t);

    while (t--)
    {
        scanf("%lld\n", &x);
        int size = 0;
        while (x > 0)
        {
            arr[size++] = (x & 1);
            x /= 2;
        }

        arr[size] = '\0';
        printf("%d\n", size);

        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}