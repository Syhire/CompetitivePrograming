#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int s;
int fenwickTree[200010] = {0};
#define LSOne(x) (x & (x * -1))

bool updateTree(int x, int count)
{
    if (x > s)
        return true;

    // printf("%d ", x);

    fenwickTree[x] += count;

    return updateTree(x + LSOne(x), count);
}

int rsq(int x)
{
    if (x <= 0)
        return 0;

    // printf("\n%d add: %d", x, fenwickTree[x]);

    return fenwickTree[x] + rsq(x - LSOne(x));
}

int main()
{
    int loop = 1;
    while (scanf("%d\n", &s) && s != 0)
    {
        if (loop != 1)
            printf("\n");

        printf("Case %d:\n", loop++);
        memset(fenwickTree, 0, sizeof(fenwickTree));
        int input;

        for (int i = 0; i < s; i++)
        {
            scanf("%d\n", &input);
            updateTree(i + 1, input);
        }

        char str[10];
        int a, b, sumA, sumB;

        while (scanf("%s\n", str) && str[0] != 'E')
        {
            scanf("%d %d\n", &a, &b);
            switch (str[0])
            {
            case 'M':
                sumA = rsq(a - 1);
                sumB = rsq(b);
                printf("%d\n", sumB - sumA);
                break;
            case 'S':
                sumA = rsq(a - 1);
                sumB = rsq(a);
                updateTree(a, b - (sumB - sumA));
                break;
            }
        }
    }
}