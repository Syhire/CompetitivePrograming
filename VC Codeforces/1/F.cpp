#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int n, m;
int minA, minB, minW;
vector<pair<int, int> > edge[200010];
queue<int> res;
bool visited[200010];

int num = 0;
bool isDone = false;

void dfs(int a) {
    // printf("# %d\n", a);
    visited[a] = true;
    num++;
    res.push(a);
    if (a == minA || isDone) {
        isDone = true;
        return;
    }
    
    for (int i = 0; i < edge[a].size(); i++)
    {
        if (!isDone && !visited[edge[a][i].first]) {
            dfs(edge[a][i].first);
        }
    }
}

int main() {
    int loop;
    scanf("%d\n", &loop);

    while (loop--)
    {
        scanf("%d %d\n", &n, &m);
        minW = INT_MAX;

        for (int i = 1; i <= n; i++)
            edge[i].clear();

        int a, b, w;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d\n", &a, &b, &w);
            edge[a].push_back(make_pair(b, w));
            edge[b].push_back(make_pair(a, w));
            if (minW > w || (minW == w && minA > min(a, b))) {
                minA = min(a, b);
                minB = max(a, b);
                minW = w;
            }
        }
        
        // printf("# %d -> %d\n", minA, minB);
        memset(visited, false, sizeof(bool) * 200010);
        // res = queue<int>();
        num = 0;

        visited[minA] = true;
        isDone = false;
        // visited[b] = true;
        dfs(minB);

        // for (int i = 1; i <= n; i++)
        // {
        //     printf("%d", visited[i]);
        // }
        // printf(" #%d\n# ANS #\n", num);
        
        printf("%d %d\n%d", minW, num + 1, minA);

        while (!res.empty())
        {
            printf(" %d", res.front());
            res.pop();
        }
        printf("\n");
        
    }
}