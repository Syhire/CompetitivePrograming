#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n, m, s, t;
vector<pair<int, int> > edge[50010];

long key[20010];

int djkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for(int i = 0; i < n; i++) key[i] = 1000000000;

    pq.push(make_pair(0, s));
    key[s] = 0;

    while (!pq.empty())
    {
        pair<int, int> f = pq.top();
        pq.pop();

        // printf("-> %d(%d), %d\n", f.second, f.first, key[f.second]);

        int len = edge[f.second].size();
        // printf("-> len: %d\n", len);

        if (key[f.second] < f.first) continue;

        for (int i = 0; i < len; i++)
        {
            pair<int, int> v = edge[f.second][i];

            // printf("--> %d(%d)\n", v.second, v.first);
            // printf("%d < %d\n", key[v.second], key[f.second]);

            if (key[v.second] > key[f.second] + v.first)
            {
                key[v.second] = key[f.second] + v.first;
                pq.push(make_pair(key[v.second], v.second));
            }
        }
    }

    return key[t];
}

int main()
{
    int count, tCase = 1;
    scanf("%d\n", &count);

    while (count--)
    {
        scanf("%d %d %d %d\n", &n, &m, &s, &t);

        for (int i = 0; i <= n; i++)
        {
            edge[i].clear();
        }

        int a, b, w;

        while (m--)
        {
            scanf("%d %d %d\n", &a, &b, &w);
            edge[a].push_back(make_pair(w, b));
            edge[b].push_back(make_pair(w, a));
        }

        int res = djkstra();
        if (res == 1000000000) printf("Case #%d: %s\n", tCase++, "unreachable");
        else printf("Case #%d: %d\n", tCase++, res);
    }
}