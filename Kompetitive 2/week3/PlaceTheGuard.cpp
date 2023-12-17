#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edge[210];

class disjointSet
{
public:
    int numEle;
    int parent[210];
    int ranks[210];

    int group[210];
    bool isVisited[210];
    bool isVisited2[210];

    disjointSet(int n)
    {
        numEle = n;

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            ranks[i] = 0;
            group[i] = 0;
            isVisited[i] = false;
            isVisited2[i] = false;
        }
    }

    int findSet(int n)
    {
        if (n != parent[n])
            parent[n] = findSet(parent[n]);
        return parent[n];
    }

    void unionSet(int a, int b)
    {
        int set1 = findSet(a);
        int set2 = findSet(b);

        if (set1 == set2)
            return;

        if (ranks[set1] == ranks[set2])
            ranks[set1]++;

        if (ranks[set1] > ranks[set2])
            parent[set2] = parent[set1];
        else
            parent[set1] = parent[set2];
    }

    int howMuchSoldierNeeded()
    {
        int sum = 0;

        for (int i = 0; i < numEle; i++)
        {
            if (!isVisited[i])
            {
                int temp = colorBipartite(i);
                if (isBipartite(findSet(i)))
                    sum+= temp;
                else
                    return -1;
            }
        }

        return sum;
    }

    int colorBipartite(int n)
    {
        queue<int> q;
        q.push(n);
        isVisited[n] = true;
        group[n] = 1;

        int sum1 = 1;
        int sum2 = 0;

        while (!q.empty())
        {
            int x = q.front();
            int groupX = group[x];
            q.pop();

            for (int i = 0; i < edge[x].size(); i++)
            {
                if (!isVisited[edge[x][i]])
                {
                    isVisited[edge[x][i]] = true;
                    group[edge[x][i]] = (groupX == 1 ? 2 : 1);
                    if (groupX == 1) sum2++;
                    else sum1++;
                    q.push(edge[x][i]);
                }
            }
        }

        return min(sum1, sum2) > 0 ? min(sum1, sum2) : max(sum1, sum2);
    }

    bool isBipartite(int n) {
        for(int i = 0; i < numEle; i++) {
            int set = findSet(i);

            if (set == n) {
                for (int j = 0; j < edge[i].size(); j++)
                {
                    if (group[i] == group[edge[i][j]]) return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    int nC, numEle, numUni;
    scanf("%d\n", &nC);

    int a, b;
    while (nC--)
    {
        scanf("%d %d\n", &numEle, &numUni);
        disjointSet ds(numEle);

        while (numUni--)
        {
            scanf("%d %d\n", &a, &b);
            ds.unionSet(a, b);

            // undirected
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        printf("%d\n", ds.howMuchSoldierNeeded());

        // reset
        for (int i = 0; i < 210; i++)
        {
            edge[i].clear();
        }
    }
}