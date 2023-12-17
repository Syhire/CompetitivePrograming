#include <stdio.h>
#include <string.h>
using namespace std;

int dp[105][105]; // barang, nilai

int dyP(int barang, int nilai) // k, n
{
    if (barang == 1)
        return 1;
    if (dp[barang][nilai] != -1)
        return dp[barang][nilai];

    // printf("-> %d %d\n", barang, nilai);

    unsigned long long sum = 0;

    for (int i = 0; i <= nilai; i++)
    {
        unsigned long long take = dyP(barang - 1, nilai - i) % 1000000;
        sum += take;
    }

    dp[barang][nilai] = sum;
    return sum % 1000000;
}

int main()
{
    int n, k; // nilai, barang

    while (scanf("%d %d\n", &n, &k) && n != 0 && k != 0)
    {
        memset(dp, -1, sizeof(int) * 105 * 105);
        printf("%d\n", dyP(k, n));
    }
}