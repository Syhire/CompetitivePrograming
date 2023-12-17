#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

vector<int> ts;
bool visited[110];
vector<int> arr[110];

void topoSort(int u)
{
    // printf("%d", u);
    visited[u] = true;
    for (int i = 0; i < arr[u].size(); i++)
    {
        if (!visited[arr[u][i]])
        {
            topoSort(arr[u][i]);
        }
    }
    ts.push_back(u);
}

int main()
{
    int n, m;
    while (scanf("%d %d\n", &n, &m) && !(n == 0 && m == 0))
    {
        ts.clear();
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++)
            arr[i].clear();

        int a, b;
        while (m--)
        {
            scanf("%d %d\n", &a, &b);
            arr[a].push_back(b);
        }

        for (int i = 1; i <= n; i++)
        {
            // printf("%d", i);
            if (!visited[i])
                topoSort(i);
        }

        for (int i = ts.size() - 1; i >= 0; i--)
            printf("%s%d", (i == ts.size() - 1) ? "" : " ", ts[i]);
        printf("\n");
    }
}