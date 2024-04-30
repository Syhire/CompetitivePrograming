#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int n, m;
vector<int> edge[100010];
int res[100010];

int main() {
    scanf("%d %d\n", &n, &m);
    int a, b;

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d\n", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    res[1] = 1;
    bool possible = true;

    for (int i = 2; i <= n; i++)
    {
        res[i] = 1;
        bool temp = false;

        // printf("=> %d\n", i);

        // check children
        for (int j = 0; j < edge[i].size(); j++)
        {
            // printf(" => %d (%d)\n", edge[i][j], res[edge[i][j]]);

            if(res[edge[i][j]] == res[i]) 
                if (temp) {
                    possible = false;
                    break;
                }
                else {
                    res[i] = 2;
                    temp = true;
                }
        }
        
        // printf("  = %d (%d)\n", i, res[i]);
    }

    if (!possible) {
        memset(res, 0, sizeof(int) * n + 1);
        res[1] = 2;
        possible = true;

        for (int i = 2; i <= n; i++)
        {
            res[i] = 1;
            bool temp = false;

            // printf("=> %d\n", i);

            // check children
            for (int j = 0; j < edge[i].size(); j++)
            {
                // printf(" => %d (%d)\n", edge[i][j], res[edge[i][j]]);

                if(res[edge[i][j]] == res[i]) 
                    if (temp) {
                        possible = false;
                        break;
                    }
                    else {
                        res[i] = 2;
                        temp = true;
                    }
            }
            
            // printf("  = %d (%d)\n", i, res[i]);
        }

        if (!possible)
            printf("IMPOSSIBLE\n");
        else
            for (int i = 1; i <= n; i++)
                printf("%d ", res[i]);
    }
    else
        for (int i = 1; i <= n; i++)
            printf("%d ", res[i]);
    
}