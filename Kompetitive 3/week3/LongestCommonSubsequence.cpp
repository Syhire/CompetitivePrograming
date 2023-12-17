#include <stdio.h>
#include <string.h>
using namespace std;

char s1[1005];
char s2[1005];

int dp[1005][1005];

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

        if (takeS1 > takeS2)
            res = takeS1;
        else
            res = takeS2;
    }

    dp[len1][len2] = res;
    return res;
}

int main()
{
    while (scanf("%[^\n]\n%[^\n]\n", s1, s2) != EOF)
    {
        int len1 = strlen(s1) - 1;
        int len2 = strlen(s2) - 1;

        memset(dp, -1, sizeof(int) * 1005 * 1005);
        // printf("%s (%d)\n%s (%d)\n = %d\n\n", s1, len1, s2, len2, LCS(len1, len2));
        printf("%d\n", LCS(len1, len2));
    }
}