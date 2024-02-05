#include <stdio.h>
#include <cmath>
#include <string.h>
using namespace std;

int dp[1000010];
int solve(int i) {
    // printf("# %d\n", i);
    if (dp[i] != -1) return dp[i];

    return dp[i] = (solve((int)floor(i - sqrt((double) i))) +
                   solve((int)floor(log((double) i))) +
                   solve((int)floor(i * sin((double) i) * sin((double) i)))) % 1000000;
}

int main() {
    memset(dp, -1, sizeof(int) * 1000010);
    dp[0] = 1;
    int input;
    while (scanf("%d\n", &input) != EOF && input != -1)
        printf("%d\n", solve(input));
}