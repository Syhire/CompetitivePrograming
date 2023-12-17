#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

int n, e, t, m;
vector<pair<int, int> > edge[50010];
long key[20010];

bool djkstra(int start, int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for(int i = 0; i < n; i++) key[i] = 1000000000;

    pq.push(make_pair(0, start));
    key[start] = 0;

    while (!pq.empty())
    {
        pair<int, int> f = pq.top();
        pq.pop();

        // printf("\n-> %d(%d), %d\n", f.second, f.first, key[f.second]);

        int len = edge[f.second].size();
        // printf("-> len: %d\n", len);

        if (key[f.second] < f.first) continue;

        for (int i = 0; i < len; i++)
        {
            pair<int, int> v = edge[f.second][i];

            // printf("%d < %d\n", key[v.second], key[f.second]);

            // printf("--> %d(%d)", v.second, v.first);
            
            if (key[v.second] > key[f.second] + v.first)
            {
                // printf(" - C");
                key[v.second] = key[f.second] + v.first;
                pq.push(make_pair(key[v.second], v.second));
            }
            // printf("\n");
        }
    }

    return key[end] <= t;
}

int main()
{
    int count, tCase = 1;
    scanf("%d\n", &count);

    while (count--)
    {
        scanf("\n%d %d %d %d\n", &n, &e, &t, &m);
        e--;

        for (int i = 0; i <= n; i++)
        {
            edge[i].clear();
        }

        int a, b, w;

        while (m--)
        {
            scanf("%d %d %d\n", &a, &b, &w);
            a--;
            b--;
            edge[a].push_back(make_pair(w, b));
            // edge[b].push_back(make_pair(w, a));
        }


        
        int sum = 0;
        for(int i = 0; i < n; i++) if(djkstra(i, e)) sum++;
        printf("%d\n", sum);

        if (count != 0) printf("\n");

        //  printf("end: %d\n", e + 1);

        //  for(int i = 0; i < n; i++) {
        //      for(int j = 0; j < edge[i].size(); j++) {
        //          printf("%d-(%d)>%d\n", i + 1, edge[i][j].first, edge[i][j].second + 1);
        //      }
        //  }

        //  for(int i = 0; i < n; i++) printf("%d ", key[i]);
        //  printf("\n");
    }
}