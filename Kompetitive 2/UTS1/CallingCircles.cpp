#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int n, m;
vector<int> edge[30];
vector<int> revEdge[30];
map<string, int> nameMap;
map<int, string> revNameMap;

stack<int> outputTopo;
bool isVisited[30];

vector<int> scc[30];

void topoSort(int x);
void dfs(int x, int cnt);

int main()
{
    int caseCC = 1;
    while (scanf("%d %d\n", &n, &m) && n != 0 && m != 0)
    {
        // reset variables
        int count = 1;
        char in1[30], in2[30];
        for (int i = 0; i < 30; i++)
        {
            edge[i].clear();
            revEdge[i].clear();
            scc[i].clear();
        }
        nameMap.clear();
        revNameMap.clear();

        fill(isVisited, isVisited + 30, false);

        // input
        for (int i = 0; i < m; i++)
        {
            scanf("%s %s\n", in1, in2);
            // reg input
            if (nameMap[in1] <= 0)
            {
                nameMap[in1] = count;
                revNameMap[count++] = in1;
            }
            if (nameMap[in2] <= 0)
            {
                nameMap[in2] = count;
                revNameMap[count++] = in2;
            }

            edge[nameMap[in1]].push_back(nameMap[in2]);
            revEdge[nameMap[in2]].push_back(nameMap[in1]);
        }

        // find topo
        for (int i = 1; i < count; i++)
        {
            if (!isVisited[i])
            {
                topoSort(i);
            }
        }

        fill(isVisited, isVisited + 30, false);

        // dfs SCC
        int cnt = 0;
        while (!outputTopo.empty())
        {
            if (!isVisited[outputTopo.top()])
                dfs(outputTopo.top(), cnt++);
            // printf("%s\n", revNameMap[outputTopo.top()].c_str());
            outputTopo.pop();
        }

        // output

        printf("Calling circles for data set %d:\n", caseCC++);

        for (int i = 0; i < cnt; i++)
        {
            sort(scc[i].begin(), scc[i].end());

            for (int j = 0; j < scc[i].size(); j++)
            {
                printf("%s%s", j == 0 ? "" : ", ", revNameMap[scc[i][j]].c_str());
            }

            printf("\n");
        }
    }
}

void topoSort(int x)
{
    isVisited[x] = true;

    for (int i = 0; i < edge[x].size(); i++)
    {
        if (!isVisited[edge[x][i]])
            topoSort(edge[x][i]);
    }

    outputTopo.push(x);
}

void dfs(int x, int cnt)
{
    isVisited[x] = true;
    scc[cnt].push_back(x);
    for (int i = 0; i < revEdge[x].size(); i++)
    {
        if (!isVisited[revEdge[x][i]])
            dfs(revEdge[x][i], cnt);
    }
}