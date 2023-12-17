#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int sizeM;
int matrix[20][20];

void row(int a, int b);
void col(int a, int b);
void inc();
void dec();
void transpose();
void printMatrix();

int main()
{
    int numCase = 1;
    int count, countCmd, tempInput, a, b;
    char cmd[15];
    scanf("%d\n", &count);

    while (count--)
    {
        scanf("%d\n", &sizeM);

        for (int i = 0; i < sizeM; i++)
            for (int j = 0; j < sizeM; j++)
            {
                scanf("%c\n", &tempInput);
                matrix[i][j] = tempInput - '0';
            }

        scanf("%d\n", &countCmd);
        while (countCmd--)
        {
            scanf("%s\n", cmd);

            if (strcmp(cmd, "row") == 0)
            {
                scanf("%d %d\n", &a, &b);
                row(a, b);
            }
            else if (strcmp(cmd, "col") == 0)
            {
                scanf("%d %d\n", &a, &b);
                col(a, b);
            }
            else if (strcmp(cmd, "inc") == 0)
                inc();
            else if (strcmp(cmd, "dec") == 0)
                dec();
            else if (strcmp(cmd, "transpose") == 0)
                transpose();
        }

        printf("Case #%d\n", numCase++);
        printMatrix();
    }
}

void row(int a, int b)
{
    swap(matrix[a - 1], matrix[b - 1]);
}

void col(int a, int b)
{
    for (int i = 0; i < sizeM; i++)
        swap(matrix[i][a - 1], matrix[i][b - 1]);
}

void inc()
{
    for (int i = 0; i < sizeM; i++)
        for (int j = 0; j < sizeM; j++)
            matrix[i][j] = (matrix[i][j] + 1) % 10;
}

void dec()
{
    for (int i = 0; i < sizeM; i++)
        for (int j = 0; j < sizeM; j++)
            matrix[i][j] = (10 + matrix[i][j] - 1) % 10;
}

void transpose()
{
    for (int i = 0; i < sizeM; i++)
        for (int j = i + 1; j < sizeM; j++)
            swap(matrix[i][j], matrix[j][i]);
}

void printMatrix()
{
    for (int i = 0; i < sizeM; i++)
    {
        for (int j = 0; j < sizeM; j++)
            printf("%d", matrix[i][j]);

        printf("\n");
    }
    printf("\n");
}