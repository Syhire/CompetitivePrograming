#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int revDir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char dirChar[] = {'D', 'U', 'R', 'L'};        

int n, m;
char map[1000][1000];

pair<int, int> start;
pair<int, int> destination;

short dirMap[1000][1000];
int moves[1000][1000];

bool solve()
{
    bool visited[1000][1000] = {false};
    queue<pair<int, int> > q;
    q.push(start);
    moves[start.first][start.second] = 0;

    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();

        if (front.first == destination.first && front.second == destination.second)
            return true;

        visited[front.first][front.second] = true;

        for (int i = 0; i < 4; i++)
        {
            int nX = front.first + dir[i][0];
            int nY = front.second + dir[i][1];

            if (nX < 0 || nX >= n || nY < 0 || nY >= m)
                continue;
            if (visited[nX][nY])
                continue;
            if (map[nX][nY] == '#')
                continue;

            visited[nX][nY] = true;
            dirMap[nX][nY] = i;
            moves[nX][nY] = moves[front.first][front.second] + 1;
            // printf("=> %d %d %d\n", nX, nY, dirMap[nX][nY]);
            q.push(make_pair(nX, nY));
        }
    }

    return false;
}

void printSol(int x, int y) {
    if (map[x][y] == 'A') return;
    
    int move = dirMap[x][y];
    printSol(x + revDir[move][0], y + revDir[move][1]);
    printf("%c", dirChar[dirMap[x][y]]);
}

int main()
{
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf("%c\n", &map[i][j]);
            if (map[i][j] == 'A')
                start = make_pair(i, j);
            if (map[i][j] == 'B')
                destination = make_pair(i, j);
        }

    bool res = solve();

    // printf("%d\n")


    if (res) {
        printf("YES\n");
        int move = moves[destination.first][destination.second];
        printf("%d\n", move);
        printSol(destination.first, destination.second);
        printf("\n");
    } else
        printf("NO\n");
}