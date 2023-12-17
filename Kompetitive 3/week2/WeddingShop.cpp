#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int money, c;
vector<int> garment[25];
int sizeGarment[25];

int dp[205][25]; // money, index
int cumSum;
int maxSum;

int dyP(int money, int index)
{
    if (money < 0)
        return -1;
    if (index == -1)
        return 0;
    if (dp[money][index] != -1)
        return dp[money][index];

    int sum = -1;

    for (int i = 0; i < sizeGarment[index]; i++)
    {
        int harga = garment[index][i];
        // printf("-> %d - %d (%d)\n", money, harga, index);
        int take = dyP(money - harga, index - 1);
        // printf("--> %d (%d, %d) = %d\n", index, money, harga, take);

        if (take != -1)
            if (sum < take + harga)
                sum = take + harga;
    }

    dp[money][index] = sum;
    return sum;
}

int main()
{
    int testCase;

    scanf("%d\n", &testCase);

    while (testCase--)
    {
        scanf("%d %d\n", &money, &c);

        int input;
        for (int i = 0; i < c; i++)
        {
            scanf("%d ", &sizeGarment[i]);
            garment[i].clear();

            for (int j = 0; j < sizeGarment[i]; j++)
            {
                scanf("%d\n", &input);
                garment[i].push_back(input);
            }
        }

        memset(dp, -1, sizeof(int) * 205 * 25);
        int sum = dyP(money, c - 1);

        if (sum == -1)
            printf("no solution\n");
        else
            printf("%d\n", sum);
    }
}