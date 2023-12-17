#include <stdio.h>
#include <bitset>
#include <string.h>
#include <cmath>
using namespace std;

int n;
int weight[32800]; // 2 ^ 15 = 32768
int potent[32800];

int main()
{
    while (scanf("%d\n", &n) != EOF)
    {
        memset(weight, 0, sizeof(weight));
        memset(potent, 0, sizeof(potent));

        int size = (int)pow(2.0, (n * 1.0));

        for (int i = 0; i < size; i++)
            scanf("%d\n", &weight[i]);

        for (int i = 0; i < size; i++)
        {
            for (bitset<16> selector(1); selector.to_ulong() < size; selector <<= 1) // neightbor
            {
                potent[i] += weight[i ^ selector.to_ulong()];
            }
        }

        int maxPotentSum = -1;

        for (int i = 0; i < size; i++)
        {
            for (bitset<16> selector(1); selector.to_ulong() < size; selector <<= 1)
            {
                int potentSum = potent[i] + potent[i ^ selector.to_ulong()];
                if (potentSum > maxPotentSum)
                    maxPotentSum = potentSum;
            }
        }

        printf("%d\n", maxPotentSum);
    }
}