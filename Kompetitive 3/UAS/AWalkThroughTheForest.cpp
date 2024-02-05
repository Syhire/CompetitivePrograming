#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
#include <string.h>
using namespace std;

int n, m;
vector<pair<int, int> > edge[1010];

int best;
int hasil[1010];
int dp[1010];

int countDAG(int from) {
    // if (from == 2) return 1; udah di main pake dp[2] = 1
    if (dp[from] != -1) return dp[from];
    int res = 0;

    // printf("# %d\n", from);

    for (int i = 0; i < edge[from].size(); i++)
    {
        int to = edge[from][i].first;
        if (hasil[to] < hasil[from]) res += countDAG(to);
    }

    dp[from] = res;
    return res;
}

void djkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    // memset(hasil, 200000, sizeof(int) * 1010);
    for (int i = 1; i <= n; i++)
        hasil[i] = INT_MAX;
    
    hasil[2] = 0;
    q.push(make_pair(0, 2)); // weight, to

    while (!q.empty())
    {
        int from = q.top().second;
        int weight = q.top().first;
        q.pop();

        // printf("=> %d\n", from);

        for (int i = 0; i < edge[from].size(); i++)
        {
            int to = edge[from][i].first;
            int wTo = edge[from][i].second;

            // printf("==> %d [%d]\n", to, wTo);

            if (hasil[to] > hasil[from] + wTo)
            {
                hasil[to] = hasil[from] + wTo;
                q.push(make_pair(hasil[to], to));
            }
        }
    }
}

int main()
{
    while (scanf("%d %d\n", &n, &m) != EOF && n != 0)
    {
        int a, b, d;
        for (int i = 1; i <= n; i++)
            edge[i].clear();

        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d\n", &a, &b, &d);
            edge[a].push_back(make_pair(b, d));
            edge[b].push_back(make_pair(a, d));
        }

        djkstra();

        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%d\n", hasil[i]);
        // }

        memset(dp, -1, sizeof(int) * 1010);
        dp[2] = 1;
        printf("%d\n", countDAG(1));

        // printf("---\n");
    }
}