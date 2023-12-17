#include <stdio.h>
using namespace std;

int s, d;
int manyD;
int tempD;
int month[15];
int max;

int sumMonth(int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
        sum += month[i];
    return sum;
}

int checkFiveMonth(int max)
{
    for (int i = 0; i < max; i++)
    {
        if (sumMonth(i, i + 4) > 0)
            return false;
    }

    return true;
}

void generate(int len)
{

    if (len == 12)
    {
        if (checkFiveMonth(len - 4))
        {
            int temp = sumMonth(0, 11);
            if (temp > max)
            {
                // for (int i = 0; i < 12; i++)
                //     printf("%d ", month[i]);
                // printf("\n");
                max = temp;
            }
        }
        return;
    }

    month[len] = s;
    if (checkFiveMonth(len - 4)) // 5 -> 1, 6 -> 2, ..., 12 -> 7
        generate(len + 1);

    month[len] = -1 * d;
    tempD++;
    if (tempD <= manyD)
        generate(len + 1);
    tempD--;
}

int main()
{
    while (scanf("%d %d\n", &s, &d) != EOF)
    {
        max = -1;
        manyD = 12;
        generate(0);
        if (max >= 0)
            printf("%d\n", max);
        else
            printf("%s\n", "Deficit");
    }
}