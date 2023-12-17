#include <stdio.h>
#include <string.h>
using namespace std;

int n, k;
int nums[100010][200010];
int total = 0;
// int cum = 0;

int solve(int num, int sum)
{
    // if () // base case
    // {
    //     total++;
    // }

    for (int i = num + 1; i > 0; i--)
    {
    }
}

int main()
{
    scanf("%d %d\n", &n, &k);
    memset(nums, -1, sizeof(int) * 100010 * 200010);
    solve(n - 1, k);
    printf("%d\n", total);
}