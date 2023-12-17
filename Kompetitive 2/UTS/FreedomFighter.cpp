#include <queue>
#include <stdio.h>
#include <utility>

using namespace std;

int n, secB, secP, fight;
char arr[60][60];

int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfsB(int x, int y)
{
  // printf("  B: %d, %d -> %c\n", x, y, arr[x][y]);

  queue<pair<int, int>> q;
  q.push(make_pair(x, y));

  while (!q.empty())
  {
    pair<int, int> f = q.front();
    q.pop();

    int fx = f.first;
    int fy = f.second;
    arr[fx][fy] = '#';

    for (int i = 0; i < 4; i++)
    {
      int nx = fx + dir[i][0];
      int ny = fy + dir[i][1];

      if (nx < 0 || nx >= n)
        continue;
      if (ny < 0 || ny >= n)
        continue;
      if (arr[nx][ny] == 'B')
      {
        q.push(make_pair(nx, ny));
      }
    }
  }
}

void bfsP(int x, int y)
{
  // printf("  P: %d, %d -> %c\n", x, y, arr[x][y]);
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));

  while (!q.empty())
  {
    pair<int, int> f = q.front();
    q.pop();

    int fx = f.first;
    int fy = f.second;
    arr[fx][fy] = '#';

    for (int i = 0; i < 4; i++)
    {
      int nx = fx + dir[i][0];
      int ny = fy + dir[i][1];

      if (nx < 0 || nx >= n)
        continue;
      if (ny < 0 || ny >= n)
        continue;
      if (arr[nx][ny] == 'P')
      {
        q.push(make_pair(nx, ny));
      }
    }
  }
}

int groupP, groupB;

void handleGroups(int x, int y)
{
  if (arr[x][y] == 'B')
  {
    groupB++;
    bfsB(x, y);
  }
  else if (arr[x][y] == 'P')
  {
    groupP++;
    bfsP(x, y);
  }
  else if (arr[x][y] == '#')
    arr[x][y] = '*';
}

void bfsGroups(int x, int y)
{

  queue<pair<int, int>> q;
  q.push(make_pair(x, y));

  while (!q.empty())
  {
    pair<int, int> f = q.front();
    q.pop();

    int fx = f.first;
    int fy = f.second;
    handleGroups(fx, fy);
    // printf(" G: %d, %d -> %c\n", x, y, arr[fx][fy]);

    for (int i = 0; i < 4; i++)
    {
      int nx = fx + dir[i][0];
      int ny = fy + dir[i][1];

      if (nx < 0 || nx >= n)
        continue;
      if (ny < 0 || ny >= n)
        continue;
      if (arr[nx][ny] == '.' || arr[nx][ny] == '*')
        continue;

      q.push(make_pair(nx, ny));
    }
  }
}

void handleSector(int x, int y)
{
  if (arr[x][y] == 'B' || arr[x][y] == 'P')
  {
    groupB = 0, groupP = 0;
    bfsGroups(x, y);

    secB += groupB;
    secP += groupP;

    if (groupB > 0 && groupP > 0)
      fight += groupB + groupP;
  }
  else
    arr[x][y] = '.';
}

void bfsSector(int x, int y)
{
  // printf("S: %d, %d -> %c\n", x, y, arr[x][y]);
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));

  while (!q.empty())
  {
    pair<int, int> f = q.front();
    q.pop();

    int fx = f.first;
    int fy = f.second;
    handleSector(fx, fy);

    // dfs lanjut ke vertical and/or horizontal
    for (int i = 0; i < 4; i++)
    {
      int nx = fx + dir[i][0];
      int ny = fy + dir[i][1];

      if (nx < 0 || nx >= n)
        continue;
      if (ny < 0 || ny >= n)
        continue;
      if (arr[nx][ny] == '.')
        continue;

      q.push(make_pair(nx, ny));
    }
  }
}

int main()
{
  while (scanf("%d\n", &n) && n != 0)
  {
    for (int i = 0; i < n; i++)
      scanf("%s\n", arr[i]);

    // for ( int i = 0; i < n; i++){
    // for ( int j = 0; j < n; j++) printf("%c  ", arr[i][j]);
    // printf("\n");
    // }

    int sector = 1;
    fight = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (arr[i][j] == '*' || arr[i][j] == 'B' || arr[i][j] == 'P')
        {
          secB = 0, secP = 0;
          bfsSector(i, j);
          printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy "
                 "group(s)\n",
                 sector++, secB, secP);
        }

    printf("Total %d group(s) are in fighting position.\n\n", fight);
  }
  return 0;
}
