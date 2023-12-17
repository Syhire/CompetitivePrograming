#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> arr;
    vector<string> arrSort;

    int loop = 0;

    scanf("%d\n", &loop);

    int i;
    char name[15];
    string nameString;

    for (i = 0; i < loop; i++)
    {
        scanf("%s", name);
        nameString = name;
        arr.push_back(nameString);
    }

    arrSort = arr;

    sort(arrSort.begin(), arrSort.end());

    bool inc = true;
    bool dec = true;

    for (i = 0; i < loop; i++)
    {
        if (arrSort[i] != arr[i])
            inc = false;
        if (arrSort[loop - i - 1] != arr[i])
            dec = false;
    }

    if (inc == true)
        printf("%s", "INCREASING");
    else if (dec == true)
        printf("%s", "DECREASING");
    else
        printf("%s", "NEITHER");
}