#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char map[1000][1000]; // .(floor), #(wall), x(visited)

int dir[][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void bfs(int x, int y)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();

        int fX = front.first;
        int fY = front.second;

        if (map[fX][fY] == '#') continue;
        map[fX][fY] = '#';

        for (int i = 0; i < 4; i++)
        {
            int nX = fX + dir[i][0];
            int nY = fY + dir[i][1];

            if (nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if (map[nX][nY] == '.') q.push(make_pair(nX, nY));
        }
    }
}

int main()
{
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%c\n", &map[i][j]);

    int res = 0;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == '.') {
                bfs(i, j);
                res++;
            }

        
    printf("%d\n", res);
}