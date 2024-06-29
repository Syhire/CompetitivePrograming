#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int t;
char map[15][15];
// vector<int> black;
vector<pair<int, int> > white;

int maxN = 0;

int dir[][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void printMap() {
    for (int i = 0; i < 10; i++)
        printf("%s\n", map[i]);
}

void solve(int x, int y, int num) {
    printMap();
    printf("\n");
    maxN = max(num, maxN);
    // printf("%d %d\n", x, y);

    for (int i = 0; i < 4; i++)
    {
        int nX = x + dir[i][0];
        int nY = y + dir[i][1];

        int n2X = nX + dir[i][0];
        int n2Y = nY + dir[i][1];

        if (map[nX][nY] != 'B') continue;
        if (map[n2X][n2Y] != '#') continue;
        if (n2X >= 10 || n2X < 0 || n2Y >= 10 || n2Y < 0) continue;

        map[x][y] = '#';
        map[n2X][n2Y] = 'W';
        map[nX][nY] = '#';
        solve(n2X, n2Y, num + 1);
        map[nX][nY] = 'B';
        map[n2X][n2Y] = '#';
        map[x][y] = 'W';
    }
}

int main() {
    scanf("%d\n", &t);

    while (t--)
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                scanf("%c\n", &map[i][j]);
                if (map[i][j] == 'W') white.push_back(make_pair(i, j));
            }

        for (int i = 0; i < white.size(); i++)
            solve(white[i].first, white[i].second, 0);

        printf("%d\n", maxN);
    }
    
}