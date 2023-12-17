#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

char s1[50];
char s2[50];
int dp[50][50];
int solution[50][50];
// stack<string> output;

void printSol(int len1, int len2)
{
    if (len1 == 0 && len2 == 0)
        return;
        
    if (solution[len1][len2] == 1)
        printSol(len1 - 1, len2 - 1);
    else if (solution[len1][len2] == 2)
    {
        printSol(len1 - 1, len2);
        printf("D%c%02d", s1[len1 - 1], len1 + 1);
    }
    else if (solution[len1][len2] == 3)
    {
        printSol(len1, len2 - 1);
        printf("I%c%02d", s2[len2 - 1], len2);
    }
    else
    {
        printSol(len1 - 1, len2 - 1);
        printf("C%c%02d", s2[len2 - 1], len2);
    }
}

int EditDistance(int len1, int len2)
{
    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;

    if (dp[len1][len2] != -1)
        return dp[len1][len2];

    printf("-> %d, %d\n", len1, len2);

    int res = 0;

    if (s1[len1 - 1] == s2[len2 - 1])
    {
        res = EditDistance(len1 - 1, len2 - 1);
        solution[len1 - 1][len2 - 1] = 1;
    }
    else
    {
        int delS1 = 1 + EditDistance(len1 - 1, len2);
        int delS2 = 1 + EditDistance(len1, len2 - 1);
        int chngS = 1 + EditDistance(len1 - 1, len2 - 1);

        // printf("--> %d, %d > delS1: %d, delS2: %d, Change: %d\n", len1, len2, delS1, delS2, chngS);

        // res = min(delS1, min(delS2, chngS));
        if (delS1 < delS2)
        {
            if (delS1 < chngS)
            {
                // delS1 min
                res = delS1;
                solution[len1 - 1][len2] = 2;
                // output.push("D1");
            }
            else
            {
                // chngS min
                res = chngS;
                solution[len1 - 1][len2 - 1] = 4;
                // output.push("C");
            }
        }
        else
        {
            if (delS2 < chngS)
            {
                // chngS min
                res = delS2;
                solution[len1][len2 - 1] = 3;
                // output.push("D2");
            }
            else
            {
                // delS2 min
                res = chngS;
                solution[len1 - 1][len2 - 1] = 3;
                // output.push("C");
            }
        }
    }

    printf("# > %d, %d = %d\n", len1, len2, res);

    dp[len1][len2] = res;
    return res;
}

int main()
{
    while (scanf("%s\n", s1) && s1[0] != '#')
    {
        scanf("%s\n", s2);

        int len1 = strlen(s1);
        int len2 = strlen(s2);
        memset(dp, -1, sizeof(int) * 50 * 50);

        printf("%d\n", EditDistance(len1, len2));
        printSol(len1 - 1, len2 - 1);
        printf("E\n");
    }
}