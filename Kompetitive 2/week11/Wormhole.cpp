#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

#define INT_MAX 2147483647

int n, m;
vector<pair<int, int> > edge[1010];

bool BellmanFord()
{
    int distance[1010];

    for (int i = 0; i < n; i++)
        distance[i] = INT_MAX;

    // solar system kite
    distance[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        // loop every vertex
        for (int v = 0; v < n; v++)
        {
            if (distance[v] == INT_MAX)
                continue;

            // get all edge from vertex v
            for (int e = 0; e < edge[v].size(); e++)
            {
                if (distance[v] + edge[v][e].second < distance[edge[v][e].first])
                    distance[edge[v][e].first] = distance[v] + edge[v][e].second;
            }
        }
    }

    // loop every vertex check if there's smoller weight (if yes, then its a negative cycles)
    for (int v = 0; v < n; v++)
    {
        if (distance[v] == INT_MAX)
            continue;

        // get all edge from vertex v
        for (int e = 0; e < edge[v].size(); e++)
        {
            if (distance[v] + edge[v][e].second < distance[edge[v][e].first])
                return true;
        }
    }

    return false;
}

int main()
{
    int countCase;
    scanf("%d\n", &countCase);

    for (int loop = 0; loop < countCase; loop++)
    {
        scanf("%d %d\n", &n, &m);

        for (int i = 0; i < n; i++)
            edge[i].clear();

        int x, y, t;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d\n", &x, &y, &t);
            edge[x].push_back(make_pair(y, t));
        }

        printf("%s\n", BellmanFord() ? "possible" : "not possible");
    }
}