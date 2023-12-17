#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int sizeArr = 9;
char arr[30][30];

int FloodFill(int x, int y, char c)
{
    int sum = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    arr[x][y] == 'Y';

    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();

        int fx = front.first;
        int fy = front.second;
        // printf("- %d %d\n", fx, fy);

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int nx = fx + i;
                int ny = fy + j;

                if (0 > nx || nx >= sizeArr)
                    continue;
                if (0 > ny || ny >= sizeArr)
                    continue;
                if (arr[nx][ny] != c && arr[nx][ny] != '.')
                    continue;

                // printf("-- %d %d\n", nx, ny);

                sum++;
                q.push(make_pair(nx, ny));
                arr[nx][ny] = 0;
            }
        }
    }

    return sum;
}

int main()
{
    int count;
    scanf("%d\n", &count);
    while (count--)
    {
        for (int i = 0; i < sizeArr; i++)
            scanf("%s\n", &arr[i]);

        int white = 0;
        int black = 0;

        for (int i = 0; i < sizeArr; i++)
            for (int j = 0; j < sizeArr; j++)
                if (arr[i][j] == 'X')
                {
                    white++;
                }
                else if (arr[i][j] == 'O')
                {
                    black++;
                }
                else 
                {
                    
                }

        printf("Black %d White %d\n", black, white);
    }
}