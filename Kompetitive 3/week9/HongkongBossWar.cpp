#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int q, b;
map<int, int> questIndex;
pair<int, int> bossNode[110];

vector<int> edge[210];
vector<int> edgeRev[210];

void add_path(int a, int b)
{
    printf("=> %d v %d\n", a, b);

    printf("%d -> %d\n", -a, b);
    edge[100 + (-a)].push_back(100 + b);

    printf("%d -> %d\n", -b, a);
    edge[100 + (-b)].push_back(100 + a);
}

bool solve(int index)
{

    for (int i = 0; i < index; i++)
    {
    }
}

int solve()
{
    // 1 .. b / 2
    printf("%d\n", solve(b));
    return -1;
}

int main()
{
    int count = 0, caseCount = 1;
    scanf("%d\n", &count);

    while (caseCount <= count)
    {
        scanf("%d %d\n", &q, &b);

        // get quest
        int q1, q2;
        for (int i = 1; i <= q; i++)
        {
            scanf("%d %d\n", &q1, &q2);
            // quest[i] = make_pair(q1, q2);
            questIndex[q1] = i;
            questIndex[q2] = -i;
        }

        // get boss
        int b1, b2;
        for (int i = 1; i <= b; i++)
        {
            scanf("%d %d\n", &b1, &b2);
            // boss[i] = make_pair(b1, b2);
            bossNode[i] = make_pair(questIndex[b1], questIndex[b2]);
            // add_path(bossNode[i].first, bossNode[i].second);
            // printf("%d v %d\n", bossNode[i].first, bossNode[i].second);
        }

        printf("###\n");
        int res = solve();
        printf("Case #%d: %d\n", caseCount++, res);
    }
}