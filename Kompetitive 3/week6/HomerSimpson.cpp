#include <stdio.h>
#include <algorithm>
using namespace std;

int m, n, t;

pair<int, int> dp[10010];

pair<int, int> maxPair(pair<int, int> a, pair<int, int> b)
{

    if (a.second < b.second)
        return a;
    else if (b.second < a.second)
        return b;
    else
    {
        if (a.first >= b.first)
            return a;
        else
            return b;
    }
}

int main()
{
    while (scanf("%d %d %d\n", &m, &n, &t) != EOF)
    {
        dp[0] = make_pair(0, 0);

        for (int i = 1; i <= t; i++)
        {
            pair<int, int> ambilM = make_pair(-1, i + 1);
            pair<int, int> ambilN = make_pair(-1, i + 1);
            pair<int, int> gaAmbil = make_pair(0, i);

            if (i - m >= 0)
                ambilM = make_pair(dp[i - m].first + 1, dp[i - m].second);

            if (i - n >= 0)
                ambilN = make_pair(dp[i - n].first + 1, dp[i - n].second);

            dp[i] = maxPair(ambilM, maxPair(ambilN, gaAmbil));

            // printf("%d = %d, %d; M: %d, %d; N: %d, %d; G: %d, %d\n", i, dp[i].first, dp[i].second, ambilM.first, ambilM.second, ambilN.first, ambilN.second, gaAmbil.first, gaAmbil.second);
        }

        if (dp[t].second > 0)
            printf("%d %d\n", dp[t].first, dp[t].second);
        else
            printf("%d\n", dp[t].first);
    }
}