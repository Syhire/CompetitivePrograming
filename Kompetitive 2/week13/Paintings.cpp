#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <utility>
using namespace std;

int n, anti;
map<string, int> color;
map<int, string> revColor;

bool antiColor[20][20];
int wallpaper[20];
bool taken[20];

int sum;
string first;

bool checkAntiColor(int len)
{
    if (len - 1 > -1)
        return antiColor[wallpaper[len]][wallpaper[len - 1]];

    return false;
}

void KaryString(int len)
{
    if (len == n)
    {
        if (first.compare("") == 0)
        {
            first += revColor[wallpaper[0]];
            for (int i = 1; i < n; i++)
            {
                first += " " + revColor[wallpaper[i]];
                // printf("%s ", revColor[wallpaper[i]].c_str());
            }
            // printf("\n");
        }
        sum++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!taken[i])
        {
            taken[i] = true;
            wallpaper[len] = i;
            if (!checkAntiColor(len))
                KaryString(len + 1);
            wallpaper[len] = 0;
            taken[i] = false;
        }
    }
}

int main()
{
    int tcase;
    scanf("%d\n", &tcase);

    while (tcase--)
    {
        // memset(wallpaper, 0xFF, sizeof(int) * 20); // buat -1
        memset(wallpaper, 0, sizeof(int) * 20);
        memset(antiColor, false, sizeof(bool) * 20 * 20);
        sum = 0;
        first = "";

        scanf("%d\n", &n);

        char tempStr[25], tempStr2[25];
        for (int i = 1; i <= n; i++)
        {
            scanf("%s\n", tempStr);

            color[tempStr] = i;
            revColor[i] = tempStr;
        }

        scanf("%d\n", &anti);
        while (anti--)
        {
            scanf("%s %s\n", tempStr, tempStr2);
            antiColor[color[tempStr]][color[tempStr2]] = true;
            antiColor[color[tempStr2]][color[tempStr]] = true;
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%s: ", revColor[i].c_str());

        //     for (int j = 1; j <= n; j++)
        //     {
        //         printf("%s, ", antiColor[i][j] ? revColor[j].c_str() : "-");
        //     }

        //     printf("\n");
        // }
        // printf("\n");
        KaryString(0);
        printf("%d\n", sum);
        printf("%s\n", first.c_str());
        // printf("\n");
    }
}