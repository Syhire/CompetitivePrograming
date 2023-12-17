#include <stdio.h>
#include <string>
#include <string.h>
#include <utility>
using namespace std;

int sizeO;
int maxWeight;
int ks[110][110];
int time[110];
int score[110];
string desc[110];

int knapsack(int i, int culTime)
{

    if (i >= sizeO)
        return 0;
    if (ks[i][culTime] != 0)
        return ks[i][culTime];

    // printf("%d %d, %d\n", i, w, first);

    int culScore = 0;

    if (culTime + time[i] <= maxWeight)
    {
        // printf("%d\n", second);
        int take = knapsack(i + 1, culTime + time[i]) + score[i];
        int noTake = knapsack(i + 1, culTime);

        if (take > noTake)
            culScore = take;
        else
            culScore = noTake;
    }
    else
        culScore = knapsack(i + 1, culTime);

    ks[i][culTime] = culScore;
    return culScore;
}

int main()
{
    int testCase;
    scanf("%d\n\n", &testCase);

    while (testCase--)
    {

        scanf("%d\n", &sizeO);

        int input1, input2;
        char inputDesc[120];
        for (int i = 0; i < sizeO; i++)
        {
            printf("a");
            scanf("%d %d %s\n", &input1, &input2, inputDesc);
            score[i] = input1;
            time[i] = input2;
            // desc[i] = inputDesc;
        }

        int maxVal = 0;

        maxWeight = 240;
        memset(ks, 0, sizeof(int) * 110 * 110);
        maxVal += knapsack(0, 0);

        printf("%d\n", maxVal);
    }
}