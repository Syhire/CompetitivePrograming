#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int m, n;
bool maps[10010][10010];

bool bfsDeposit(int x, int y);
int findDeposit();

int main()
{
    char input;
    while (scanf("%d %d\n", &m, &n) && m != 0 && n != 0)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                scanf("%c\n", &input);
                if (input == '*')
                    maps[i][j] = 0;
                else
                    maps[i][j] = 1;
            }

        printf("%d\n", findDeposit());
    }
}

int findDeposit()
{
    int sum = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (maps[i][j] == 1 && bfsDeposit(i, j)) 
                sum++;
        }

    return sum;
}

bool bfsDeposit(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    maps[x][y] == 0;

    while(!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int fx = front.first;
        int fy = front.second;
        // printf("- %d %d\n", fx, fy);
        
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int nx = fx + i;
                int ny = fy + j;

                if (0 > nx || nx >= m) continue; 
                if (0 > ny || ny >= n) continue;
                if (!maps[nx][ny]) continue;

                // printf("-- %d %d\n", nx, ny);

                q.push(make_pair(nx, ny));
                maps[nx][ny] = 0;
                
            }
        }
    }

    return true;
}