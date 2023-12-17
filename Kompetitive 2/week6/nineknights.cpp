#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

char arr[10][10];
int n;

int checkKnight(int x, int y);
bool checkIsValidPosition();

int main()
{
    while (scanf("%s", arr[n]) != EOF)
        n++;

    printf("%s", checkIsValidPosition() ? "valid" : "invalid");
}

bool checkIsValidPosition()
{
    bool valid = true;
    int num = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(arr[i]); j++)
        {
            if (arr[i][j] == 'k')
            {
                num++;
                if (checkKnight(i, j))
                    valid = false;
            }
        }
    }

    return num == 9 ? valid : false;
}

int checkKnight(int x, int y)
{
    // printf("%d,%d\n", x, y);

    for (int i = -2; i <= 2; i++)
    {
        for (int j = -2; j <= 2; j++)
        {
            if (i == 0 || j == 0 || abs(i) == abs(j))
                continue;

            int nX = x + i;
            int nY = y + j;

            if (nX < 0 || nX >= n || nY < 0 || nY >= n)
                continue;

            // printf("check: %d, %d\n", nX, nY);

            if (arr[nX][nY] == 'k')
                return true;
        }
    }
    return false;
}