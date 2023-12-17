#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int n, countDep;
vector<int> edge[110];
bool visited[110];

void dfs(int idx)
{
    visited[idx] = true;
    countDep++;

    for (int j = 0; j < edge[idx].size(); j++)
    {
        if (visited[edge[idx][j]] == false)
            dfs(edge[idx][j]);
    }
}

int main()
{
    while (scanf("%d\n", &n) && n != 0)
    {
        int many, input;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d\n", &many);
            edge[i].clear();
            while (many--)
            {
                scanf("%d\n", &input);
                edge[i].push_back(input);
            }
        }

        int maxDep = -1, maxInd = -1;
        for (int i = 1; i <= n; i++)
        {
            memset(visited, false, sizeof(visited));
            countDep = 0;
            dfs(i);
            // printf("%d: %d\n", i, countDep);
            if (countDep > maxDep)
            {
                maxDep = countDep;
                maxInd = i;
            }
        }

        printf("%d\n", maxInd);
    }
}