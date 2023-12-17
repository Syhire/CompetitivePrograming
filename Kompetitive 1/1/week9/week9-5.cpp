#include <stdio.h>
#include <map>
using namespace std;

int main()
{
    int count, countIdx;

    scanf("%d", &count);

    map<int, bool> busStop;

    int input;

    for (countIdx = 0; countIdx < count; countIdx++)
    {
        scanf("%d", &input);

        busStop[input] = true;
    }

    int lower = 1;

    for (int i = 1; i < 1001; i++)
    {
        if (!busStop[i])
            continue;

        lower = i;

        while (busStop[i + 1])
            i++;

        if (i - lower >= 2)
            printf("%d-%d ", lower, i);
        else if (lower == i)
            printf("%d ", lower);
        else
            printf("%d %d ", lower, i);
    }
}