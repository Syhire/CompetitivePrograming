#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    int count, countIdx;

    scanf("%d\n", &count);

    string temp = "";
    string output = "";

    char input[1000000];

    for (countIdx = 0; countIdx < count; countIdx++)
    {
        scanf("%[^\n]\n", input);

        printf("%s", input);
    }
}