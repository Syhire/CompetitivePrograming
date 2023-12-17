#include <stdio.h>
#include <vector>
using namespace std;

int n;
int weight[1010];
vector<int> door[1010];

int move(int i)
{
    int maxValue = 1;

    for (int j = 0; j < i; j++)
    {
        int temp = move(j) + 1;
        maxValue = max(maxValue, temp);
    }

    return maxValue;
}

int main()
{
    scanf("%d\n", &n);

    int k, a;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d ", &weight[i], &k);

        while (k--)
        {
            scanf("%d \n", &a);
            door[i].push_back(a);
        }
    }
}