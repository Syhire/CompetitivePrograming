#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int M, N;
int continent[20][20];
char contChar[20][20];
int a, b;

int findMaxRec(int x, int y);
int findMaxLand();

int main()
{
    char input;

    char landChar;

    while (scanf("%d %d\n", &M, &N) != EOF)
    {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                scanf("%c\n", &input);
                contChar[i][j] = input;
            }

        scanf("%d %d\n", &a, &b);

        landChar = contChar[a][b];

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                continent[i][j] = contChar[i][j] == landChar ? 1 : 0;

        // for(int i = 0; i <M ; i++) {
        //     for (int j = 0; j < N; j++)
        //         printf("%d ", continent[i][j]);
        //     printf("\n");
        // }

        printf("%d\n", findMaxLand());
    }
}

int findMaxLand()
{
    int max = -1;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int sum = 0;
            if (continent[i][j] == 1)
            {
                // printf("test\n");
                sum = findMaxRec(i, j);
            }
            // printf("%d", sum);

            if (sum > max)
            {
                max = sum;
            }
        }

        // printf("\n");
    }

    return max;
}

int findMaxRec(int x, int y)
{
    queue<pair<int, int> > q;

    bool kingContinent = false;
    int sum = 0;

    q.push(make_pair(x, y));

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        sum++;

        // printf("DEBUG: %d %d\n", u.first, u.second);
        continent[u.first][u.second] = 0;

        if (u.first == a && u.second == b)
            kingContinent = true;

        q.pop();

        // x + 1, y DOWN
        if (u.first + 1 < M)
            if (continent[u.first + 1][u.second] == 1)
            {
                q.push(make_pair(u.first + 1, u.second));
                continent[u.first + 1][u.second] = 0;
            }

        // x - 1, y UP
        if (u.first - 1 >= 0)
            if (continent[u.first - 1][u.second] == 1)
            {
                q.push(make_pair(u.first - 1, u.second));
                continent[u.first - 1][u.second] = 0;
            }

        // x , y + 1 KANAN
        if (u.second + 1 < N)
        {
            if (continent[u.first][u.second + 1] == 1)
            {
                q.push(make_pair(u.first, u.second + 1));
                continent[u.first][u.second + 1] = 0;
            }
        }
        else if (continent[u.first][0] == 1)
        {
            q.push(make_pair(u.first, 0));
            continent[u.first][0] = 0;
        }

        // x , y - 1 Kiri
        if (u.second - 1 >= 0)
        {
            if (continent[u.first][u.second - 1] == 1)
            {
                q.push(make_pair(u.first, u.second - 1));
                continent[u.first][u.second - 1] = 0;
            }
        }
        else if (continent[u.first][N - 1] == 1)
        {
            q.push(make_pair(u.first, N - 1));
            continent[u.first][N - 1] = 0;
        }
    }

    // printf("%d\n", sum);

    return kingContinent ? 0 : sum;
}