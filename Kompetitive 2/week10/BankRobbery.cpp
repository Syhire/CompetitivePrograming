#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

int n, m, b, p;
vector<pair<int, int> > edge[50010];

vector<int> banks;
vector<int> police;

long key[20010];

int djkstra(int start)
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

    int min = 1000000000;

    for(int i = 0; i < police.size(); i++) {
        if (min > key[police[i]]) min = key[police[i]];
    }

    return min;
}

int main()
{
    while (scanf("%d %d %d %d\n", &n, &m, &b, &p) != EOF)
    {
        // printf("%d %d %d %d\n", n, m, b, p);

        banks.clear();
        police.clear();
        for (int i = 0; i <= n; i++) edge[i].clear();
        
        int u, v, w;

        while (m--)
        {
            scanf("%d %d %d\n", &u, &v, &w);
            edge[u].push_back(make_pair(w, v));
            edge[v].push_back(make_pair(w, u));
        }

        int temp;

        while(b--) {
            scanf("%d\n", &temp);
            banks.push_back(temp);
        }

        while(p--) {
            scanf("%d\n", &temp);
            police.push_back(temp);
        }

        int max = -1;
        int sumMax = 0;
        vector<int> furtherBanks;

        for(int i = 0; i < banks.size(); i++) {
            int res = djkstra(banks[i]);
            // printf("%d, %d\n",banks[i], res);

            if (res > max) {
                max = res;
                sumMax = 0;
                furtherBanks.clear();
            }

            if (res >= max) {
                furtherBanks.push_back(banks[i]);
                sumMax++;
            }
        }
        // printf("\n");

        if (max != 1000000000) printf("%d %d\n", sumMax, max);
        else printf("%d *\n", sumMax);
        
        for(int i = 0; i < furtherBanks.size(); i++) printf("%d ", furtherBanks[i]);
        printf("\n");

        //  printf("end: %d\n", e + 1);

        //  for(int i = 0; i < n; i++) {
        //      for(int j = 0; j < edge[i].size(); j++) {
        //          printf("%d-(%d)-%d\n", i, edge[i][j].first, edge[i][j].second);
        //      }
        //  }

        //  for(int i = 0; i < n; i++) printf("%d ", key[i]);
        //  printf("\n");
    }
}