#include <stdio.h>
#include <string.h>
using namespace std;

int s1[200005];
int s2[200005];
int dp[200005][200005];

int EditDistance(int len1, int len2)
{
    if (len1 == 0 && len2 == 0)
        return 0;
    else if (len1 < 0 && len2 >= 0)
        return len2 + 1;
    else if (len1 >= 0 && len2 < 0)
        return len1 + 1;

    if (dp[len1][len2] != -1)
        return dp[len1][len2];

    printf("-> %d, %d\n", len1, len2);

    int res = 0;

    if (s1[len1] == s2[len2])
    {
        res = EditDistance(len1 - 1, len2 - 1);
    }
    else
    {
        int delS1 = 1 + EditDistance(len1 - 1, len2);
        int delS2 = 1 + EditDistance(len1, len2 - 1);

        printf("--> %d, %d\n delS1: %d\n delS2: %d\n", len1, len2, delS1, delS2);

        if (delS1 < delS2)
            res = delS1;
        else
            res = delS2;
    }

    printf("# > %d, %d = %d\n", len1, len2, res);

    dp[len1][len2] = res;
    return res;
}

int main()
{
    int tc, testCase = 1;
    scanf("%d\n", &tc);
    while (testCase <= tc)
    {
        int len;
        scanf("%d\n", &len);

        for (int i = 0; i < len; i++)
            scanf("%d\n", &s1[i]);
        for (int i = 0; i < len; i++)
            scanf("%d\n", &s2[i]);

        memset(dp, -1, sizeof(int) * 2005 * 2005);

        len--;
        printf("Case %d: %d\n", testCase++, EditDistance(len, len));
    }
}