#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

int n;
int s, t, c;

vector<int> edge[110];
int map[110][110];
// int nMap[110][110];

int bsf()
{

    queue<int> q; // node, min value
    int parent[110];
    int res[110]; // min edge

    memset(res, -1, sizeof(int) * 110);

    q.push(s);
    parent[s] = -1;
    res[s] = INT_MAX;

    while (!q.empty())
    {
        int from = q.front();
        q.pop();

        // if (res[from] != -1 && from == s)
        //     continue;

        for (int i = 0; i < edge[from].size(); i++)
        {
            int to = edge[from][i];

            // printf("%d %d (%d) (%d)\n", from, to, map[from][to], res[to]);
            if (map[from][to] <= 0)
                continue;
            if (res[to] != -1)
                continue;

            res[to] = min(map[from][to], res[from]);
            parent[to] = from;
            q.push(to);
        }
    }

    // for (int i = 1; i < n + 1; i++)
    // {
    //     printf("%d (%d) ", res[i], parent[i]);
    // }
    // printf("\n");

    if (res[t] != -1)
    {
        int to = t;
        int from = parent[to];
        while (from != -1)
        {
            map[from][to] -= res[t];
            map[to][from] += res[t];

            // next
            to = from;
            from = parent[to];
        }
    }

    return res[t];
}

int solve()
{
    int startAgain = true;
    int res = 0;

    while (startAgain)
    {
        startAgain = false;
        int resLoop = bsf();
        if (resLoop != -1)
        {
            startAgain = true;
            // printf("%d\n", resLoop);
            res += resLoop;
        }
    }

    return res;
}

int main()
{
    int cNetwork = 1;
    while (scanf("%d\n", &n) && n != 0)
    {
        scanf("%d %d %d\n", &s, &t, &c);
        memset(map, 0, sizeof(int) * 110 * 110);

        int a, b, w;
        for (int i = 0; i < c; i++)
        {
            scanf("%d %d %d\n", &a, &b, &w);
            // printf("%d %d %d\n", a, b, w);
            if (map[a][b] == 0)
                edge[a].push_back(b);
            map[a][b] += w;
            // nMap[b][a] = 0;

            if (map[b][a] == 0)
                edge[b].push_back(a);
            map[b][a] += w;
            // nMap[a][b] = 0;
            // printf("%d %d (%d)\n", a, b, map[a][b]);
        }

        printf("Network %d\n", cNetwork++);
        printf("The bandwidth is %d.\n\n", solve());
    }
}