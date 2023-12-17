#include <stdio.h>
#include <set>
using namespace std;

int main()
{
    int count, countIdx;

    scanf("%d", &count);

    set<int> freeDay;

    int lowerDay, upperDay;

    for (countIdx = 0; countIdx < count; countIdx++)
    {
        scanf("%d %d", &lowerDay, &upperDay);

        for (int i = lowerDay; i <= upperDay; i++)
            freeDay.insert(i);
    }

    printf("%d", freeDay.size());
}