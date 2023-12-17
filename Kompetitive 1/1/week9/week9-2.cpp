#include <stdio.h>
#include <set>
#include <string>
using namespace std;

int main()
{
    int count, countIdx;
    set<string> setIns;

    char inputIns[21];
    char inputTeams[21];

    scanf("%d\n", &count);

    for (countIdx = 0; countIdx < count; countIdx++)
    {
        scanf("%s %s\n", inputIns, inputTeams);
        int sizeOld = setIns.size();
        setIns.insert(inputIns);
        int sizeNew = setIns.size();

        if (sizeNew > sizeOld)
            printf("%s %s\n", inputIns, inputTeams);

        if (sizeNew == 12)
            break;
    }
}