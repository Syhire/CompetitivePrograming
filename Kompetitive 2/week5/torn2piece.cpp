#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int countVertex, countEdge;
map<string, int> mapName;
map<int, string> revMapName;
vector<int> mapEdge[1100];

deque<int> route;
int destination;
int parent[1100];

bool recDFS(int x);
bool BFS(int x);

int main()
{
    fill(parent, parent + 1100, -1);
    scanf("%d\n", &countEdge);

    int loop = countEdge;

    char edge1[25], edge3[25];
    char edgeMore[1000];
    int i = 1;

    while (loop--)
    {
        scanf("%s %[^\n]\n", edge1, edgeMore);

        if (mapName[edge1] <= 0)
        {
            mapName[edge1] = i;
            revMapName[i++] = edge1;
        }

        char *ptr = strtok(edgeMore, " ");
        while (ptr != NULL)
        {
            string edge2 = ptr;

            if (mapName[edge2] <= 0)
            {
                mapName[edge2] = i;
                revMapName[i++] = edge2;
            }

            mapEdge[mapName[edge1]].push_back(mapName[edge2]);
            mapEdge[mapName[edge2]].push_back(mapName[edge1]);
            ptr = strtok(NULL, " ");
        }
    }

    scanf("%s %s\n", edge1, edge3);
    destination = mapName[edge3];
    bool res = BFS(mapName[edge1]);

    if (res)
    {
        stack<string> resStack;
        int cur = mapName[edge3];
        while (parent[cur] != -1)
        {
            resStack.push(revMapName[cur]);
            cur = parent[cur];
        }

        resStack.push(revMapName[cur]);

        while (!resStack.empty())
        {
            printf("%s ", resStack.top().c_str());
            resStack.pop();
        }

        printf("\n");
    }
    else
    {
        printf("no route found\n");
    }
}

bool isVisited[110];

bool BFS(int x)
{
    queue<int> q;
    q.push(x);
    isVisited[x] = true;

    while (!q.empty())
    {
        int u = q.front();
        if (u == destination)
            return true;
        q.pop();

        for (int i = 0; i < mapEdge[u].size(); i++)
        {
            int next = mapEdge[u][i];
            if (!isVisited[next])
            {
                q.push(next);
                isVisited[next] = true;
                parent[next] = u;
            }
        }
    }

    return false;
}