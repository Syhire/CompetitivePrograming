#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s1[205];
char s2[205];

int dp[205][205];

int EditDistance(int len1, int len2)
{
    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;

    // printf("-> %d, %d\n", len1, len2);

    if (dp[len1][len2] != -1)
        return dp[len1][len2];

    int res = 0;

    if (s1[len1 - 1] == s2[len2 - 1])
        res = EditDistance(len1 - 1, len2 - 1);
    else
    {
        int delS1 = 1 + EditDistance(len1 - 1, len2);
        int delS2 = 1 + EditDistance(len1, len2 - 1);
        int repl = 1 + EditDistance(len1 - 1, len2 - 1);

        res = min(delS1, min(delS2, repl));
    }

    // printf("---> %d, %d = %d\n", len1, len2, res);
    dp[len1][len2] = res;
    return res;
}

int main()
{
    int testCase;
    scanf("%d\n", &testCase);

    while (testCase--)
    {
        fgets(s1, 205, stdin);
        fgets(s2, 205, stdin);

        s1[strcspn(s1, "\n")] = 0;
        s2[strcspn(s2, "\n")] = 0;

        int len1 = strlen(s1);
        int len2 = strlen(s2);

        memset(dp, -1, sizeof(int) * 205 * 205);
        // printf("# %s(%d)\n# %s(%d)\n= %d\n", s1, len1, s2, len2, EditDistance(len1, len2));
        printf("%d\n", EditDistance(len1, len2));
    }
}