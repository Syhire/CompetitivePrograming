#include <stdio.h>
#include <algorithm>
#include <set>

std::set<int> sets[2010];
int sum[2010] = {0};
int arr[2010];

int main()
{
    int count;
    scanf("%d\n", &count);
    int max = 0;

    for (int i = 0; i < count; i++)
    {
        scanf("%d\n", &arr[i]);
        int j = i;
        while (arr[j] - 1 != -2) { j = arr[j] - 1; }
        if (sets[j].find(arr[i]) == sets[j].end()) {
            sum[j]++;
            if (sum[j] > max) max = sum[j];
        }
        sets[j].insert(arr[i]);
    }

    printf("%d", max);
}