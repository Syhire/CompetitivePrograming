#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define SET(a, i) (a = a | (1 << i))
#define UNSET(a, i) (a = a & (1 << i))
#define READ(a, i) (a & (1 << i))
#define IF110(a, i) ((a & (7 << i)) == (6 << i))
#define IF011(a, i) ((a & (7 << i)) == (3 << i))
#define CHANGE(a, i) (a ^ (7 << i))

int dp[5000];

int charBitToInt(char bit[], int many)
{
    int two = 1;
    int res = 0;
    for (int i = many - 1; i >= 0; i--, two *= 2)
        if (bit[i] == 'o')
            res += two;

    return res;
}

int countPebble(int bits)
{
    int res = 0;
    printf("bits: %d - ", bits);
    for (int i = 0; i < 12; i++)
    {
        printf("%d", (bits & (1 << i)) > 0);
        if ((bits & (1 << i)) > 0)
            res++;
    }
    printf("\n");
    return res;
}

int solve(int bits)
{
    if (dp[bits] != -1)
        return dp[bits];

    int res = countPebble(bits);

    for (int i = 0; i < 10; i++)
    {
        // printf("i: %d(%d)\n", i, (bits & (1 << i)) > 0);
        // printf("%d\n", bits & (1 << i));
        if (IF110(bits, i))
        {
            // printf("110: %d\n", i);
            int newBits = CHANGE(bits, i);
            res = min(res, solve(newBits));
        }

        if (IF011(bits, i))
        {
            // printf("011: %d\n", i);
            int newBits = CHANGE(bits, i);
            res = min(res, solve(newBits));
        }
    }

    return dp[bits] = res;
}

int main()
{
    int tCase, bits;
    scanf("%d\n", &tCase);

    char input[15];
    memset(dp, -1, sizeof(int) * 5000);

    while (tCase--)
    {
        scanf("%s\n", input);
        bits = charBitToInt(input, 12);
        // printf("%d\n", bits);
        printf("%d\n", solve(bits));
    }
}