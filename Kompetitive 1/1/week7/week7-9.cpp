#include <stdio.h>
#include <math.h>
// work
int main()
{
    unsigned int n;

    scanf("%u\n", &n);

    unsigned int num;
    unsigned int sum = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%u", &num);
        sum += num;
    }

    if (sum % 3 == 0)
        printf("yes");
    else
        printf("no");
}