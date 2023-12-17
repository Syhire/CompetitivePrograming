#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int cases, gridSize;
char maps[105][105];

bool findShipRec(int x, int y);
int findShip();

int main()
{
    scanf("%d\n", &cases);
    int nCase = 1;

    while (nCase <= cases)
    {
        scanf("%d\n", &gridSize);

        for (int i = 0; i < gridSize; i++)
        {
            for (int j = 0; j < gridSize; j++)
            {
                scanf("%c\n", &maps[i][j]);
            }
        }

        printf("Case %d: %d\n", nCase++, findShip());
    }
}

int findShip()
{
    int sum = 0;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (maps[i][j] == 'x' && findShipRec(i, j))
                sum++;
        }
    }

    return sum;
}

bool findShipRec(int x, int y)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    maps[x][y] = '.';

    while (!q.empty())
    {
        // printf("test");
        pair<int, int> u = q.front();
        q.pop();

        int i = u.first;
        int j = u.second;

        // i + 1 DOWN
        if (i + 1 < gridSize && (maps[i + 1][j] == 'x' || maps[i + 1][j] == '@'))
        {
            q.push(make_pair(i + 1, j));
            maps[i + 1][j] = '.';
        }

        // i - 1 UP
        if (i - 1 >= 0 && (maps[i - 1][j] == 'x' || maps[i - 1][j] == '@'))
        {
            q.push(make_pair(i - 1, j));
            maps[i - 1][j] = '.';
        }

        // j + 1 LEFT
        if (j + 1 < gridSize && (maps[i][j + 1] == 'x' || maps[i][j + 1] == '@'))
        {
            q.push(make_pair(i, j + 1));
            maps[i][j + 1] = '.';
        }

        // j - 1 RIGHT
        if (j - 1 >= 0 && (maps[i][j - 1] == 'x' || maps[i][j - 1] == '@'))
        {
            q.push(make_pair(i, j - 1));
            maps[i][j - 1] = '.';
        }
    }

    return true;
}