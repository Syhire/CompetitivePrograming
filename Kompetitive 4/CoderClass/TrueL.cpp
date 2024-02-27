#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int t, n;
char input[834];

vector<int> edge[5010];

int findParent(char a)
{
    if (a <= 41)
        return -22;
    if (a <= 57)   // 0
        return 48; // 48 (0) + 0
    if (a <= 90)   // - 10
        return 55; // 65 (A) - 10
    if (a <= 122)  // - 36
        return 61; // 97 (a) - 36

    return 0;
}

int findBinary(int idx)
{
    int size = ceil(n / 6.0);
    for (int i = 0; i < size; i++)
    {
        int num = input[i] - findParent(input[i]);
        printf("%c (%d)\n", input[i], num);

        for (int j = 5; j >= 0; j--)
        {
            int bin = num >> j;
            if (bin & 1)
            {
                printf("%d -> %d\n", idx, i * 6 + 5 - j);
                edge[idx].push_back(i * 6 + 5 - j);
            }
        }
        // printf("\n");
    }
}

bool findLoop()
{
}

int main()
{
    scanf("%d\n", &t);

    while (t--)
    {
        scanf("%d\n", &n);

        // reset
        for (int i = 0; i < n; i++)
            edge[i].clear();

        for (int i = 0; i < n; i++)
        {
            scanf("%s\n", input);
            findBinary(i);
            // printf("%c, %d, %d\n", input, findParent(input), input - findParent(input));
        }

        bool res = findLoop();
        printf(res ? "SERU PISAN\n" : "MANA SERUNYA\n");
    }
}