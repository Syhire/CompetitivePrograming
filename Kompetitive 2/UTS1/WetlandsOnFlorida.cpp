#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <string.h>
using namespace std;

int n, m;
vector<string> land;
bool visited[110][110];

int FloodFill(int x, int y) {
    int sum = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();
        sum++;

        int fx = f.first;
        int fy = f.second;

        // printf("- %d %d\n", fx, fy);

         for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;

                int nx = fx + i;
                int ny = fy + j;

                if (nx < 0 || nx >= n) continue;
                if (ny < 0 || ny >= m) continue;
                if (visited[nx][ny] || land[nx][ny] == 'L') continue;

                // printf("-- %d %d\n", nx, ny);

                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    return sum;
}

void handleOutput(char input[]) {
    int a, b;
    sscanf(input, "%d %d", &a, &b);
    a--;
    b--;
    // printf("%d, %d -> %d\n", a, b, FloodFill(a, b));
    printf("%d\n", FloodFill(a, b));
    memset(visited, false, sizeof(visited));
}

int main() {
    int count;
    scanf("%d\n", &count);

    while (count--)
    {
        char input[110];
        // fgets(input, 100, stdin);
        int idx = 0;

        land.clear();
        memset(visited, false, sizeof(visited));

        while(true) {
            fgets(input, 100, stdin);
            if (input[0] != 'W' && input[0] != 'L') break;
            input[strcspn(input, "\r\n")] = 0;
            land.push_back(input);
        }

        n = land.size();
        m = land[0].size();

        // printf("sz: %d %d\n", n, m);

        // for(int i = 0; i < n; i++){
        // for(int j = 0; j < m; j++)
        // printf("%c ", land[i][j]); printf("\n");}

        // first case
        handleOutput(input);

        while (fgets(input, 100, stdin) != NULL)
        {
            if (input[0] == '\n') break;
            handleOutput(input);
        }

        if (count > 0) printf("\n");
    }
    
    return 0;
}