#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int countVertex;
vector<int> mapEdge[1100];

int dfs_num[1100];
int dfs_low[1100];
int dfs_parent[1100];

bool articulationPoint[1100];

void recDFS(int x);
void dfs();

int main()
{
    int edge1, edge2;
    char edgeMore[10010];

    while (scanf("%d\n", &countVertex) && countVertex != 0)
    {
        // reset
        for (int i = 0; i < 1100; i++)
        {
            mapEdge[i].clear();
            dfs_num[i] = 0;
            dfs_low[i] = 0;
            dfs_parent[i] = 0;
            articulationPoint[i] = false;
        }
        int sumPoint = 0;

        // printf("hello\n");
        while (scanf("%d", &edge1) && edge1 != 0)
        {
            scanf("%[^\n]\n", edgeMore);
            // printf("%d: ", edge1);
            edge1--;
            char *ptr = strtok(edgeMore, " ");

            while (ptr != NULL)
            {
                sscanf(ptr, "%d", &edge2);
                edge2--;
                // printf("%d ", edge2 - 1);
                mapEdge[edge1].push_back(edge2);
                mapEdge[edge2].push_back(edge1);
                ptr = strtok(NULL, " ");
            }
            // printf("\n");
        }

        dfs();
        for (int i = 0; i < countVertex; i++)
        {
            if (articulationPoint[i])
                sumPoint++;
        }
        printf("%d\n", sumPoint);
    }
}

int cnt;
int dfsRoot;
int rootChild;

void dfs()
{
    cnt = 1;
    for (int i = 0; i < countVertex; i++)
        if (dfs_num[i] == 0)
        {
            dfsRoot = i;
            rootChild = 0;
            recDFS(i);
            articulationPoint[dfsRoot] = (rootChild > 1);
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
            }
            dfs_low[x] = min(dfs_low[next], dfs_low[x]);
        }
        else if (dfs_parent[x] != next)
        {
            dfs_low[x] = min(dfs_low[x], dfs_num[next]);
        }
    }
}