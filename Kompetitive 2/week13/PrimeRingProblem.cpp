#include <stdio.h>
#include <math.h>
using namespace std;

int n;
int arr[20];
int taken[20];
int sum = 0;

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;

    return true;
}

void bitString(int len)
{
    if (len == n + 1)
    {
        if (isPrime(arr[n] + arr[1]))
        {
            for (int i = 1; i <= n; i++)
                if (i == 1) printf("%d", arr[i]); else printf(" %d", arr[i]);
            printf("\n");
        }
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {

            if (isPrime(i + arr[len - 1]) && !taken[i])
            {
                arr[len] = i;
                taken[i] = true;
                bitString(len + 1);

                arr[len] = 0;
                taken[i] = false;
            }
        }
    }
}

int main()
{
    int tcase = 1;
    arr[1] = 1;
    taken[1] = true;

    while (scanf("%d\n", &n) != EOF)
    {
        if (tcase > 1)
            printf("\n");
        printf("Case %d:\n", tcase++);
        bitString(2);
    }
}