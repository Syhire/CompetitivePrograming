#include <stdio.h>

int sizeArr = 8;

bool checkR(char arr[10][10])
{
    int i, j, count;

    for (i = 0; i < sizeArr; i++)
    {
        count = 0;
        for (j = 0; j < sizeArr; j++)
            if (arr[i][j] == 'R')
                count++;

        if (count == 8)
            return true;
    }

    return false;
}

int main()
{
    int count, i, j, z;

    scanf("%d\n", &count);

    char arr[10][10] = {'.'};

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < sizeArr; j++)
            scanf("%s", arr[j]);

        if (checkR(arr))
            printf("R\n");
        else
            printf("B\n");
    }
}