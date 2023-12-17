#include <stdio.h>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int n, m;
vi edge[30];
map<string, int> nameMap;
map<int, string> revNameMap;
stack<int> stackSCC;
bool isVisited[30] = {false};

void TopoSearch(int u);

int main()
{
    int j = 1;
    while (scanf("%d %d\n", &n, &m) && n != 0 && m != 0)
    {
        int count = 1;
        char in1[30], in2[30];

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
        }

        printf("Calling circles for data set %d:\n", j++);

        for (int i = 1; i < count; i++)
        {
            if (!isVisited[i])
            {
                TopoSearch(i);
            }
        }

        while (!stackSCC.empty())
        {
            printf("%s\n", revNameMap[stackSCC.top()].c_str());
            stackSCC.pop();
        }
    }
}

void TopoSearch(int u)
{
    isVisited[u] = true;
    for (int i = 1; i < n; i++)
    {
        if (!isVisited[edge[u][i]])
            TopoSearch(edge[u][i]);
    }

    stackSCC.push(u);
}