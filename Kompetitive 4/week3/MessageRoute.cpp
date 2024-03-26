#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int n, m;
vector<int> edge[100010];

int parent[100010];
int moves[100010];

bool bfs()
{
    memset(parent, 0, sizeof(int) * 100010);
    queue<int> q;
    q.push(1);
    moves[1] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        if (front == n)
            return true;

        for (int i = 0; i < edge[front].size(); i++)
        {
            int next = edge[front][i];
            if (parent[next] != 0)
                continue;

            moves[next] = moves[front] + 1;
            parent[next] = front;
            q.push(next);
        }
    }

    return false;
}

void printSol(int num)
{
    if (num == 1)
    {
        printf("%d", num);
        return;
    }

    printSol(parent[num]);
    printf(" %d", num);
}

int main()
{
    scanf("%d %d\n", &n, &m);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d\n", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    bool res = bfs();

    if (res)
    {
        printf("%d\n", moves[n]);
        printSol(n);
    }
    else 
        printf("IMPOSSIBLE\n");
}