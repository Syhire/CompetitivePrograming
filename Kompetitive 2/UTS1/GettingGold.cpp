#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>
#include <string.h>
using namespace std;

int gold = 0;
int w, h;
char arr[60][60];
bool isVisited[60][60];

void DFS(int x, int y)
{
    if (arr[x][y] == '#' || isVisited[x][y])
        return;
    if (arr[x][y] == 'G')
        gold++;
    isVisited[x][y] = true;

    // check trap
    if (arr[x][y + 1] == 'T')
        return;
    if (arr[x + 1][y] == 'T')
        return;
    if (arr[x][y - 1] == 'T')
        return;
    if (arr[x - 1][y] == 'T')
        return;

    DFS(x, y + 1);
    DFS(x + 1, y);
    DFS(x, y - 1);
    DFS(x - 1, y);
}

int main()
{
    int temp = 1;
    while (scanf("%d %d\n", &h, &w) != EOF)
    {
        for (int i = 0; i < w; i++)
            scanf("%s\n", arr[i]);

        memset(isVisited, 0, sizeof(isVisited));

        gold = 0;
        bool done = false;

        // printf("%d: ", temp++);

        for (int i = 0; i < w && !done; i++)
            for (int j = 0; j < h; j++)
                if (arr[i][j] == 'P' && !isVisited[i][j])
                {
                    DFS(i, j);
                    done = true;
                    break;
                }

        printf("%d\n", gold);
    }
    
    return 0;
}