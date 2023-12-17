#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int m, n;
char arr[110][110];

void FloodFill (int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    arr[x][y] == '.';

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
                if (arr[nx][ny] == '.') continue;

                // printf("-- %d %d\n", nx, ny);

                q.push(make_pair(nx, ny));
                arr[nx][ny] = '.';
                
            }
        }
    }
}

int main() {
        scanf("%d %d\n", &m, &n);

        for(int i = 0; i < m; i++)
            scanf("%s\n", arr[i]);

        int sum = 0;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if (arr[i][j] == '#') {
                    sum++;
                    FloodFill(i, j);
                }

        printf("%d\n", sum);
}