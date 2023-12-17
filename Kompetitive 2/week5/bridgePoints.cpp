#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int countVertex, countEdge;
vector<int> mapEdge[110];

int dfs_num[110];
int dfs_low[110];
int dfs_parent[110];

bool articulationPoint[110];
vector<pair<int, int> > bridge;

void recDFS(int x);
void dfs();

int main()
{
    scanf("%d %d\n", &countVertex, &countEdge);

    int loop = countEdge;
    int edge1, edge2;
    while (loop--)
    {
        scanf("%d %d\n", &edge1, &edge2);
        mapEdge[edge1].push_back(edge2);
        mapEdge[edge2].push_back(edge1);
    }

    dfs();

    for (int i = 0; i < countVertex; i++)
    {
        printf("[%d / %d]\n", dfs_num[i], dfs_low[i]);
    }
}

int cnt = 1;
int dfsRoot;
int rootChild = 0;

void dfs()
{
    for (int i = 0; i < countVertex; i++)
        if (dfs_num[i] == 0)
        {
            recDFS(i);
            dfsRoot = i;
            articulationPoint[dfsRoot] = rootChild > 1;
        }
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
            if (x == dfsRoot)
                rootChild++;
            recDFS(next);

            if (dfs_low[next] >= dfs_num[x])
            {
                articulationPoint[x] = true;
                printf("articulation Point: %d\n", x);
            }
            if (dfs_low[next] > dfs_num[x])
            {
                bridge.push_back(make_pair(x, next));
                printf("Bridge: <%d, %d>\n", x, next);
            }
            dfs_low[x] = min(dfs_low[next], dfs_low[x]);
        }
        else if (dfs_parent[x] != next)
        {
            dfs_low[x] = min(dfs_low[x], dfs_num[next]);
        }
    }
}