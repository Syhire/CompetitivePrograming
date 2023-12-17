#include <stdio.h>
// work
int main()
{
    int sizeX = 5;
    int sizeY = 4;

    int i, j;

    int n;
    int sum;

    int max = -1;
    int idxMax = -1;

    for (i = 0; i < sizeX; i++)
    {
        sum = 0;
        for (j = 0; j < sizeY; j++)
        {
            scanf("%d", &n);
            sum += n;
        }

        if (sum > max)
        {
            max = sum;
            idxMax = i + 1;
        }
    }

    printf("%d %d", idxMax, max);
}