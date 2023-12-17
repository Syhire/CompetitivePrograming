#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edge[10010];
bool isVisited[10010];
int sum = 0;

void dfs(int x)
{
    sum++;
    isVisited[x] = true;
    for (int i = 0; i < edge[x].size(); i++)
        if (!isVisited[edge[x][i]])
            dfs(edge[x][i]);
}

int main()
{
    int cases, n, m, l;
    scanf("%d", &cases);

    int a, b;

    while (cases != 0)
    {
        // input
        scanf("%d %d %d\n", &n, &m, &l);

        // input mx
        while (m != 0)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            m--;
        }

        // input lx
        while (l != 0)
        {
            scanf("%d", &a);
            if (!isVisited[a])
                dfs(a);
            l--;
        }

        printf("%d\n", sum);
        cases--;

        // reset
        sum = 0;
        fill(isVisited, isVisited + 10010, false);
        for (int i = 0; i <= n; i++)
            edge[i].clear();
    }
}