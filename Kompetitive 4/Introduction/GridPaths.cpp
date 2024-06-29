#include <stdio.h>
#include <string.h>
using namespace std;

bool visited[10][10];
char path[50];
int howMany = 0;

int dir[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char dirChar[] = {'D', 'U', 'L', 'R'};

void solve(int num, int x, int y) {
    if (num == 47 && x == 0 && y == 6) {
        printf("%s\n", path);
        howMany++;
    }
    if (num >= 47) return;
    if (x == 0 && y == 6) return;
    if (visited[x][y]) return;
    visited[x][y] = true;
    printf("%d (%d %d)\n", num, x, y);
    
    if (path[num] != '?') {
        int idx = 0;
        if (path[num] == 'U') idx = 1;
        else if (path[num] == 'L') idx = 2;
        else if (path[num] == 'R') idx = 3;

        int nextX = x + dir[idx][0];
        int nextY = y + dir[idx][1];

        printf(" %c: %d %d\n", path[num], nextX, nextY);

        if (nextX >= 7 || nextX < 0) return;
        if (nextY >= 7 || nextY < 0) return;
        if (visited[nextX][nextY]) return;

        printf("take\n");
        
        // visited[nextX][nextY] = true;
        solve(num + 1, nextX, nextY);
        // visited[nextX][nextY] = false;
    }
    else
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];

            // printf("%")
            printf(" #[%d, %d] => %d, %d\n", x, y, nextX, nextY);

            if (nextX >= 7 || nextX < 0) continue;
            if (nextY >= 7 || nextY < 0) continue;
            if (visited[nextX][nextY]) continue;

            printf("take\n");


            path[num] = dirChar[i];
            // visited[nextX][nextY] = true;
            solve(num + 1, nextX, nextY);
            // visited[nextX][nextY] = false;
            path[num] = '?';
        }
    
    visited[x][y] = false;
}

int main() {
    scanf("%s\n", path);
    memset(visited, false, sizeof(bool) * 10 * 10);
    // visited[0][0] = true;
    solve(0, 0, 0);
    printf("%d\n", howMany);
}