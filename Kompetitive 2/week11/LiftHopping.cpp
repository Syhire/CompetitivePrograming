#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n, k;
int T[110];
vector<pair<int, int> > edge[110]; // to , weight

int djkstra() {
    int dist[110];
    int parent[110];
    memset(parent, -1, sizeof(int) * 110);
    memset(dist, -1, sizeof(int) * 110);

    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // currentCost, from

    pq.push(make_pair(-60, 0));

    while (!pq.empty())
    {
        int from = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (k == from) return dist[k];

        for(int i = 0; i < edge[from].size(); i++) {
            int to = edge[from][i].first;
            int weight = edge[from][i].second;

            if (dist[to] == -1 || dist[to] > cost + weight + 60) {
                dist[to] = cost + weight + 60;
                parent[to] = from;
                pq.push(make_pair(dist[to], to));
            }
        }
        
    }

    return dist[k];
}

int main() {
    while (scanf("%d %d\n", &n, &k) != EOF)
    {
        // get elevator time & clear edge
        for(int i = 0; i < 110; i++) edge[i].clear();

        for(int i = 0; i < n; i++) {
            scanf("%d\n", &T[i]);
        }

        // printf("/-- STOPS --/\n");
        
        int stops[110];
        char stopArr[1000];
        int stop;

        // get stops
        for(int i = 0; i < n; i++) {
            scanf("%[^\n]\n", stopArr);

            int manyStop = 0;
            char *stopStr = strtok(stopArr, " ");
            
            while (stopStr != NULL)
            {
                sscanf(stopStr, "%d", &stop);
                stops[manyStop++] = stop;
                stopStr = strtok(NULL, " ");
            }

            for(int j = 0; j < manyStop; j++) {        
                // printf("%d: ", stops[j]);    
                for(int l = j + 1; l < manyStop; l++) {
                    // printf("%d(%d) ", stops[l], (stops[l] - stops[j]) * T[i]);    
                    edge[stops[j]].push_back(make_pair(stops[l], (stops[l] - stops[j]) * T[i]));
                    edge[stops[l]].push_back(make_pair(stops[j], (stops[l] - stops[j]) * T[i]));
                }
                // printf("\n");
            }
        }

        int res = djkstra();
        if (res == -1) printf("%s\n", "IMPOSSIBLE");
        else printf("%d\n", res);
        
        // printf("/----/\n");
    }
    
}