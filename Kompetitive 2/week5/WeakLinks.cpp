#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int countVertex, countEdge;
vector<int> mapEdge[10010];

int dfs_num[10010];
int dfs_low[10010];
int dfs_parent[10010];

vector<pair<int, int> > bridge;

void recDFS(int x);
void dfs();

int main()
{
    while (scanf("%d %d\n", &countVertex, &countEdge) && countVertex != 0 && countEdge != 0)
    {
        // reset
        for (int i = 0; i < 10010; i++)
        {
            mapEdge[i].clear();
            dfs_num[i] = 0;
            dfs_low[i] = 0;
            dfs_parent[i] = 0;
        }

        bridge.clear();

        int loop = countEdge;
        int edge1, edge2;
        while (loop--)
        {
            scanf("%d %d\n", &edge1, &edge2);
            mapEdge[edge1].push_back(edge2);
            mapEdge[edge2].push_back(edge1);
        }

        dfs();

        // sort & output
        int len = bridge.size();

        for (int i = 0; i < len; i++)
            if (bridge[i].first > bridge[i].second)
                swap(bridge[i].first, bridge[i].second);

        sort(bridge.begin(), bridge.end());

        printf("%d", len);

        for (int i = 0; i < len; i++)
            printf(" %d %d", bridge[i].first, bridge[i].second);
        
        printf("\n");
    }
}

int cnt = 1;

void dfs()
{
    for (int i = 0; i < countVertex; i++)
        if (dfs_num[i] == 0)
            recDFS(i);
}

void recDFS(int x)
{
    dfs_low[x] = dfs_num[x] = cnt++;

    for (int i = 0; i < mapEdge[x].size(); i++)
    {
        int next = mapEdge[x][i];
        if (dfs_num[next] == 0)
        {
            dfs_parent[next] = x;
            recDFS(next);

            if (dfs_low[next] > dfs_num[x])
                bridge.push_back(make_pair(x, next));

            dfs_low[x] = min(dfs_low[next], dfs_low[x]);
        }
        else if (dfs_parent[x] != next)
        {
            dfs_low[x] = min(dfs_low[x], dfs_num[next]);
        }
    }
}