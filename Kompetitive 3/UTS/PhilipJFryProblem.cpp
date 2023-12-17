#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <algorithm>
using namespace std;

#define maxNum 2147483647;

int n;
pair<int, int> trips[110]; // distance, dark matter gen
int dp[110][10010];        // many trips, current dark matter

int solve(int nTrip, int currDM)
{
    if (nTrip == n)
        return 0;
    if (dp[nTrip][currDM] != -1)
        return dp[nTrip][currDM];

    int res = maxNum;

    // take dark matter
    if (currDM > 0)
        res = min(res, solve(nTrip + 1, currDM - 1 + trips[nTrip].second) + trips[nTrip].first / 2);

    // not take dark matter
    res = min(res, solve(nTrip + 1, currDM + trips[nTrip].second) + trips[nTrip].first);

    return dp[nTrip][currDM] = res;
}

int main()
{
    while (scanf("%d\n", &n) && n != 0)
    {
        int trip, darkMatter;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d\n", &trip, &darkMatter);
            trips[i] = make_pair(trip, darkMatter);
        }

        memset(dp, -1, sizeof(int) * 110 * 10010);

        printf("%d\n", solve(0, 0));
    }
}