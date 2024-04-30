#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, x;
vector<int> price;
vector<int> pages;

int dp[100010][1010];

int solve(int num, int book) { // money, book
    if (num < 0) return -10000;
    if (book == -1) return 0;
    if (dp[num][book] != -1) return dp[num][book];
    
    int res = -1;

    int take = pages[book] + solve(num - price[book], book - 1);
    int notake = solve(num, book - 1);
    res = max(take, notake);

    return dp[num][book] = res;
}

int main() {
    scanf("%d %d\n", &n, &x);

    int input;
    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &input);
        price.push_back(input);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &input);
        pages.push_back(input);
    }

    memset(dp, -1, sizeof(dp));
    
    // printf("%ld\n", dp[x][n - 1]);
    solve(x, n - 1);

    printf("%ld\n", dp[x][n - 1]);
}