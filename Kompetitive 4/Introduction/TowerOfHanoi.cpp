#include <stdio.h>
#include <string.h>
using namespace std;

int n;

void solve(int num, int awal, int temp, int tujuan)
{
    if (num > 0)
    {
        solve(num - 1, awal, tujuan, temp);
        printf("%d %d\n", awal, tujuan);
        solve(num - 1, temp, awal, tujuan);
    }
}

int main()
{
    scanf("%d\n", &n);
    printf("%d\n", (1 << n) - 1);
    solve(n, 1, 2, 3);
}