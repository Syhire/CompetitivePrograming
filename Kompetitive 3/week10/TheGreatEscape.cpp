#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
char map[110][110];
pair<int, int> pDoor[500];
int mapTime[110][110];
int minTime;

class Node
{
public:
    int x;
    int y;
    int time;

    Node(int _x, int _y, int _time)
    {
        x = _x;
        y = _y;
        time = _time;
    }

    bool operator<(Node const &o) const
    {
        return time > o.time;
    }
};

int dir[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char dirDoor[] = {'S', 'E', 'N', 'W'};

bool solve()
{
    bool visited[110][110] = {0};
    priority_queue<Node> q;
    q.push(Node(n - 1, 0, 0));

    while (!q.empty())
    {
        Node front = q.top();
        q.pop();

        int fx = front.x;
        int fy = front.y;

        if (visited[fx][fy])
            continue;

        visited[fx][fy] = true;
        // printf("%d %d - %d\n", fx, fy, front.time);

        if (fx == 0 && fy == m - 1)
        {
            minTime = front.time;
            return true;
        }

        // kalau dari yg biasa
        if (map[fx][fy] == '.')
            for (int i = 0; i < 4; i++)
            {
                int nx = fx + dir[i][0];
                int ny = fy + dir[i][1];

                if (map[nx][ny] == '#')
                    continue;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                if (map[nx][ny] == '.' || map[nx][ny] == dirDoor[i])
                    q.push(Node(nx, ny, front.time + 1));
            }

        // kalau dari door
        if (map[fx][fy] > 65 && map[fx][fy] < 90)
        // kalau di fx sm fy di door
        {
            int index = 0;
            if (map[fx][fy] == 'E')
                index = 3;
            if (map[fx][fy] == 'S')
                index = 2;
            if (map[fx][fy] == 'W')
                index = 1;

            for (int j = 1; j <= 3; j++)
            {
                int idxJ = index + j;
                int nx = fx + dir[idxJ % 4][0];
                int ny = fy + dir[idxJ % 4][1];

                // printf("# %d %d (%d)\n", nx, ny, idxJ % 4);

                if (map[nx][ny] == '#')
                    continue;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                if (j == 2)
                { // 2 kali rotate
                    if (map[nx][ny] == '.' || map[nx][ny] == dirDoor[idxJ % 4])
                        q.push(Node(nx, ny, front.time + 2 * mapTime[fx][fy] + 1));
                }
                else
                { // 1 kali rotate
                    if (map[nx][ny] == '.' || map[nx][ny] == dirDoor[idxJ % 4])
                        q.push(Node(nx, ny, front.time + mapTime[fx][fy] + 1));
                }
            }
        }
    }

    return false;
}

int main()
{
    int cTest;
    scanf("%d", &cTest);

    while (cTest--)
    {
        int nDoor = 0;
        scanf("%d %d\n", &n, &m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                scanf("%c\n", &map[i][j]);
                if (map[i][j] > 65 && map[i][j] < 90)
                    pDoor[nDoor++] = make_pair(i, j);
            }

        // printf("# %d\n", cTest);

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //         printf("%c", map[i][j]);
        //     printf("\n");
        // }

        for (int i = 0; i < nDoor; i++)
        {
            pair<int, int> doors = pDoor[i];
            scanf("%d\n", &mapTime[doors.first][doors.second]);
        }

        bool res = solve();

        if (res)
            printf("%d\n", minTime);
        else
            printf("Poor Kianoosh\n");
    }
}