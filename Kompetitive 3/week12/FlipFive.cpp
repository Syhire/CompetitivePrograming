#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int size = 3;

#define flip(num, i) (num ^ (1 << i))
#define index(i, j) (j + i * size)

int hasil[600];
// bool visited[600];

void decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = 8; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
        if (i % 3 == 0)
            printf("\n");
    }
    printf("\n");
}

int flipping(int num, int i, int j)
{
    i = 2 - i;
    j = 2 - j;
    num = flip(num, index(i, j));
    // decToBinary(num);

    if (i + 1 < size)
    {
        num = flip(num, index((i + 1), j));
        // printf("[%d, %d]: %d\n", i + 1, j, index((i + 1), j));
        // decToBinary(num);
    }
    if (j + 1 < size)
    {
        num = flip(num, index(i, (j + 1)));
        // printf("[%d, %d]: %d\n", i, j + 1, index(i, (j + 1)));
        // decToBinary(num);
    }
    if (i - 1 >= 0)
    {
        num = flip(num, index((i - 1), j));
        // printf("[%d, %d]: %d\n", i - 1, j, index((i - 1), j));
        // decToBinary(num);
    }
    if (j - 1 >= 0)
    {
        num = flip(num, index(i, (j - 1)));
        // printf("[%d, %d]: %d\n", i, j - 1, index(i, (j - 1)));
        // decToBinary(num);
    }

    decToBinary(num);

    return num;
}

void calc()
{
    queue<int> q;
    hasil[0] = 0;

    // 9 anak pertama;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            q.push(flipping(hasil[0], i, j));
            hasil[index(i, j)] = 1;
        }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                int res = flipping(front, i, j);
                if (hasil[res] != -1)
                    continue;
                q.push(res);
                hasil[res] = hasil[front] + 1;
                printf("%d\n", hasil[res]);
            }
    }
}

int mapToInt()
{
}

int main()
{
    memset(hasil, -1, sizeof(int) * 600);
    // memset(visited, false, sizeof(int) * 600);

    // printf("%d\n", flipping(186, 2, 2));
    calc();

    printf("%d\n", hasil[481]);
}