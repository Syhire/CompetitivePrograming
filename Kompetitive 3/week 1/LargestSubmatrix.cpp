#include <stdio.h>
#include <string.h>

using namespace std;

int matrix[100][100];

int main()
{
    int testCase;
    scanf("%d\n\n", &testCase);

    while (testCase--)
    {
        int size = 0;
        char input[100][100];
        memset(matrix, 0, sizeof(int) * 100 * 100);

        while (fgets(input[size++], 100, stdin) != NULL && input[size - 1][0] != '\n')
        {
        }
        size--;

        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= size; j++)
            {

                if (input[i - 1][j - 1] == '1')
                {
                    matrix[i][j] = 1 + matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
                }
                else
                {
                    matrix[i][j] = -10000 + matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
                }
            }
        }

        // for (int i = 1; i <= size; i++)
        // {
        //     for (int j = 1; j <= size; j++)
        //         printf("%02d  ", matrix[i][j]);
        //     printf("\n");
        // }

        int maxSum = 0;

        for (int i1 = 1; i1 <= size; i1++)
            for (int j1 = 1; j1 <= size; j1++)
                for (int i2 = i1; i2 <= size; i2++)
                    for (int j2 = j1; j2 <= size; j2++)
                    {
                        int calcSum = matrix[i2][j2] + matrix[i1 - 1][j1 - 1] - matrix[i1 - 1][j2] - matrix[i2][j1 - 1];

                        if (calcSum > maxSum)
                        {
                            maxSum = calcSum;
                            // printf("%d, %d (%d) - %d, %d (%d)\n", i1, j1, matrix[i1][j1], i2, j2, matrix[i2][j2]);
                        }
                    }

        printf("%d\n", maxSum);
        if (testCase != 0)
            printf("\n");
    }
};