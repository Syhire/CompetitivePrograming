#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s1[205];
char s2[205];

int dp[205][205];

int LCS(int len1, int len2)
{
    if (len1 < 0 || len2 < 0)
        return 0;
    if (dp[len1][len2] != -1)
        return dp[len1][len2];

    int res = 0;

    if (s1[len1] == s2[len2])
    {
        res = 1 + LCS(len1 - 1, len2 - 1);
    }
    else
    {
        int takeS1 = LCS(len1, len2 - 1);
        int takeS2 = LCS(len1 - 1, len2);

        res = max(takeS1, takeS2);
    }

    dp[len1][len2] = res;
    return res;
}

int main()
{
    int countCase = 1;
    while (fgets(s1, 200, stdin) && s1[0] != '#')
    {
        fgets(s2, 200, stdin);
        
        s1[strcspn(s1, "\n")] = 0;
        s2[strcspn(s2, "\n")] = 0;

        int len1 = strlen(s1) - 1;
        int len2 = strlen(s2) - 1;

        // printf("%d: %s\n %d: %s\n", len1, s1, len2, s2);

        memset(dp, -1, sizeof(int) * 205 * 205);
        printf("Case #%d: you can visit at most %d cities.\n", countCase++, LCS(len1, len2));
    }
}