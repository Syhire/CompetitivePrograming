#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int s;
long long fenwickTree[5000010] = {0};
#define LSOne(x) (x & (x * -1))
#define loop(i, n) for (int i = 0; i < n; i++)

bool updateTree(int x, long long count)
{
    if (x > s)
        return true;

    // printf("%d ", x);

    fenwickTree[x] += count;

    return updateTree(x + LSOne(x), count);
}

long long rsq(int x)
{
    if (x <= 1)
        return 0;

    // printf("\n%d add: %d", x, fenwickTree[x]);

    return fenwickTree[x] + rsq(x - LSOne(x));
}

int main()
{
    memset(fenwickTree, 0, sizeof(fenwickTree));

    int n;
    scanf("%d %d\n", &s, &n);
    s += 10;
    long long input, count;
    char cmd;

    while(n--) {
        char inputStr[1000];
        scanf("%[^\n]\n", inputStr);

        sscanf(inputStr, "%c %lld %lld\n", &cmd, &input, &count);
        // printf("--> %c %lld %lld\n", cmd, input, count);

        switch (cmd)
        {
        case '+':
            updateTree(input + 1, count);
            // printf("->\n");
            break;
        case '?':
            printf("%d\n", rsq(input + 1));
            break;
        }
    }

    // loop(i, s)
    // {
    //     int temp = i + 1;
    //     printf("search: %d -> ", temp);
    //     int sum = rsq(temp);
    //     printf("\n");
    //     printf("res: %d\n", sum);
    // }
}