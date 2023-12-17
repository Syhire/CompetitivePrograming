#include <stdio.h>

int num = 0;
int r, c;
char arr[510][510];

bool checkWolf(int x, int y)
{
    // printf("%d,%d\n", x, y);

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i != 0 && j != 0 || (i == 0 && j == 0))
                continue;

            int nX = x + i;
            int nY = y + j;

            if (nX < 0 || nX >= r || nY < 0 || nY >= c)
                continue;

            // printf("check: %d, %d\n", i, j);

            if (arr[nX][nY] == 'S')
                return true;
        }
    }
    return false;
}

bool isSafe()
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == 'W')
            {
                num++;
                if (checkWolf(i, j))
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    scanf("%d %d\n", &r, &c);

    for (int i = 0; i < r; i++)
        scanf("%s\n", arr[i]);

    bool res = isSafe();

    if (num == 0)
    {
        printf("Yes\n");
        for (int i = 0; i < r; i++)
            printf("%s\n", arr[i]);
    }
    else
    {
        if (res)
        {
            printf("Yes\n");
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                    printf("%c", arr[i][j] == '.' ? 'D' : arr[i][j]);
                printf("\n");
            }
        }
        else
        {
            printf("No\n");
        }
    }
}