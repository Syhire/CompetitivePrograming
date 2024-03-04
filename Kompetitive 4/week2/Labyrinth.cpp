#include <stdio.h>
#include <string>
#include <queue>
using namespace std;

int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // S, N, E, W
string dirChar[] = {"D", "U", "R", "L"};           // bawah, atas, kanan, kiri

int n, m;
char map[1000][1000];

pair<int, int> start;
pair<int, int> destination;

class Moves {
    public:
        int x;
        int y;
        int moves;
        string path;

        Moves(int _x, int _y, int _moves, string _path)
        {
            x = _x;
            y = _y;
            moves = _moves;
            path = _path;
        }
};

Moves solve() {
    bool visited[1000][1000] = {false};
    queue<Moves> q;
    q.push(Moves(start.first, start.second, 0, ""));

    while (!q.empty())
    {
        Moves front = q.front();
        q.pop();

        if (front.x == destination.first && front.y == destination.second) return front;
        // printf("=> %d %d\n", front.x, front.y);

        visited[front.x][front.y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nX = front.x + dir[i][0];
            int nY = front.y + dir[i][1];

            if (nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
            if (visited[nX][nY]) continue;
            if (map[nX][nY] == '#') continue;

            visited[nX][nY] = true;
            q.push(Moves(nX, nY, front.moves + 1, front.path + dirChar[i]));
        }
    }

    return Moves(-1, -1, -1, "");
}

int main() {
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%c\n", &map[i][j]);
            if (map[i][j] == 'A') start = make_pair(i, j);
            if (map[i][j] == 'B') destination = make_pair(i, j);
        }

    Moves res = solve();

    if (res.moves != -1)
        printf("YES\n%d\n%s\n", res.moves, res.path.c_str());
    else printf("NO\n");
}