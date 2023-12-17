#include <stdio.h>
using namespace std;

int main()
{
    int n, i;

    scanf("%d", &n);

    int sum = 0, input;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &input);

        sum += input;
    }

    printf("%d", sum - n + 1);
}