#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <limits.h>
#include <queue>
using namespace std;

class Edge {
    public:
        int src, dest;
        long long weight;
    
        Edge(int a, int b, long long w) {
            src = a;
            dest = b;
            weight = w;
        }
};

int n, m;
vector<Edge> edge;
vector<int> edges[2510];

long long dist[2510];
long long temp[2510];

long long solve() {
    for (int i = 1; i <= n; i++)
        dist[i] = LLONG_MAX;
    
    dist[1] = 0;

    // printf("###\n");
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", dist[i]);
    // printf("\n###\n");

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < edge.size(); j++)
        {
            int u = edge[j].src;
            int v = edge[j].dest;
            long long w = edge[j].weight;
            // printf("=> %d %d %d\n", u, v, w);
            
            if (dist[u] != LLONG_MAX
                && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
        // printf("###\n");
        // for (int i = 1; i <= n; i++)
        //     printf("%d ", dist[i]);
        // printf("\n###\n");
    }
    
    return dist[n];
}

int visited[2510];

bool checkLoop() {
    memcpy(temp, dist, sizeof(dist));
    memset(visited, -1, sizeof(int) * 2510);
    
    for (int j = 0; j < edge.size(); j++)
    {
        int u = edge[j].src;
        int v = edge[j].dest;
        long long w = edge[j].weight;
        
        if (dist[u] != LLONG_MAX
            && dist[u] + w < dist[v])
            dist[v] = dist[u] + w;
    } 

    bool res = true;

    // DEBUG
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", dist[i] != temp[i]);
    // printf("\n");

    for (int i = 1; i <= n; i++) {
        if (visited[i] == -1) visited[i] = dist[i] != temp[i];
        if (visited[i] == true) // bfs
        {
            // printf("=> %d\n", i);
            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                int front = q.front();
                q.pop();

                for (int j = 0; j < edges[front].size(); j++)
                {
                    int n = edges[front][j];
                    if (visited[n] == -1) {
                        // printf("==> %d\n", n);
                        visited[n] = true;
                        q.push(n);
                    }
                }
                
            }
            
        }
    }
    // printf("\n");

    // DEBUG
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d ", visited[i]);
    // }
    // printf("\n");
    

    return !visited[n];
}

int main() {
    scanf("%d %d\n", &n, &m);

    int a, b;
    long long w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %lld\n", &a, &b, &w);
        // printf("%d %d %lld\n", a, b, w);
        edge.push_back(Edge(a, b, w * -1));
        edges[a].push_back(b);
    }
    
    long long res = solve();
    if (checkLoop())
        printf("%lld\n", res * -1);
    else 
        printf("-1\n");
}