#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int sizeArr;
bool arr[30][30];

void FloodFill (int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    arr[x][y] == false;

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

                if (0 > nx || nx >= sizeArr) continue; 
                if (0 > ny || ny >= sizeArr) continue;
                if (!arr[nx][ny]) continue;

                // printf("-- %d %d\n", nx, ny);

                q.push(make_pair(nx, ny));
                arr[nx][ny] = 0;
                
            }
        }
    }
}

int main() {
    int count = 1;
    while(scanf("%d\n", &sizeArr) != EOF) {
        char temp;

        for(int i = 0; i < sizeArr; i++)
            for(int j = 0; j < sizeArr; j++){
                scanf("%c\n", &temp); arr[i][j] = temp == '1';}

        int sum = 0;

        for(int i = 0; i < sizeArr; i++)
            for(int j = 0; j < sizeArr; j++)
                if (arr[i][j]) {
                    sum++;
                    FloodFill(i, j);
                }

        printf("%d: %d\n", count++, sum);

    }
}