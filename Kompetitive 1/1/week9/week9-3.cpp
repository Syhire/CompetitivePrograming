#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
using namespace std;

string changeNumber(char str[])
{
    int len = strlen(str);
    string res = "";
    for (int i = 0; i < len; i++)
    {
        char charNow = str[i];

        if ('a' <= charNow && charNow <= 'c')
        {
            res += '2';
        }
        else if ('d' <= charNow && charNow <= 'f')
        {
            res += '3';
        }
        else if ('g' <= charNow && charNow <= 'i')
        {
            res += '4';
        }
        else if ('j' <= charNow && charNow <= 'l')
        {
            res += '5';
        }
        else if ('m' <= charNow && charNow <= 'o')
        {
            res += '6';
        }
        else if ('p' <= charNow && charNow <= 's')
        {
            res += '7';
        }
        else if ('t' <= charNow && charNow <= 'v')
        {
            res += '8';
        }
        else if ('w' <= charNow && charNow <= 'z')
        {
            res += '9';
        }
    }

    return res;
}

int main()
{
    int count, countIdx;

    scanf("%d", &count);

    char str[1001];

    unordered_map<string, int> umap;

    for (countIdx = 0; countIdx < count; countIdx++)
    {
        scanf("%s", str);

        string index = changeNumber(str);

        umap[index]++;
    }

    scanf("%s", str);

    string inputLast = str;

    printf("%d\n", umap[inputLast]);
}