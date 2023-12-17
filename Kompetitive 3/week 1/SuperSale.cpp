#include <stdio.h>
#include <string.h>
#include <utility>
using namespace std;

int sizeO;
pair<int, int> object[1010]; // weight, price
int maxWeight;
int ks[1010][110];

int knapsack(int i, int w)
{

    if (i >= sizeO)
        return 0;
    if (ks[i][w] != 0)
        return ks[i][w];

    // printf("%d %d, %d\n", i, w, object[i].first);

    int price = 0;

    if (w + object[i].first <= maxWeight)
    {
        // printf("%d\n", object[i].second);
        int take = knapsack(i + 1, w + object[i].first) + object[i].second;
        int noTake = knapsack(i + 1, w);

        if (take > noTake)
            price = take;
        else
            price = noTake;
    }
    else
        price = knapsack(i + 1, w);

    ks[i][w] = price;
    return price;
}

int main()
{
    int testCase;
    scanf("%d\n\n", &testCase);

    while (testCase--)
    {
        scanf("%d\n", &sizeO);

        int input1, input2;
        for (int i = 0; i < sizeO; i++)
        {
            scanf("%d %d\n", &input1, &input2);
            // printf("%d %d\n", input1, input2);
            object[i] = make_pair(input2, input1);
        }

        int sizeP = 0;
        scanf("%d\n", &sizeP);

        int maxVal = 0;

        for (int i = 0; i < sizeP; i++)
        {
            scanf("%d\n", &maxWeight);
            memset(ks, 0, sizeof(int) * 1010 * 110);
            maxVal += knapsack(0, 0);
        }

        printf("%d\n", maxVal);
    }
}