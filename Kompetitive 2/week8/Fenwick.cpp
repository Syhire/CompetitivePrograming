#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int s;
int fenwickTree[100] = {0};
#define LSOne(x) (x & (x * -1))
#define loop(i, n) for (int i = 0; i < n; i++)

bool updateTree(int x, int count)
{
    if (x > s)
        return true;

    printf("%d ", x);

    fenwickTree[x] += count;

    return updateTree(x + LSOne(x), count);
}

int rsq(int x)
{
    if (x == 0)
        return 0;

    // printf("\n%d add: %d", x, fenwickTree[x]);

    return fenwickTree[x] + rsq(x - LSOne(x));
}

int main()
{
    memset(fenwickTree, 0, sizeof(fenwickTree));

    int n;
    scanf("%d %d\n", &n, &s);

    int input;
    loop(i, n)
    {
        scanf("%d\n", &input);
        printf("add: %d -> ", input);
        updateTree(input, 1);
        printf("\n");
    }

    printf("\n");

    loop(i, s)
    {
        int temp = i + 1;
        printf("search: %d -> ", temp);
        int sum = rsq(temp);
        printf("\n");
        printf("res: %d\n", sum);
    }
}