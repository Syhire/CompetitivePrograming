#include <stdio.h>

bool train[1010] = {0}; // 1: true, 0: false
bool revTrain[1010] = {0};

int main()
{
    int n, s;
    scanf("%d %d\n", &n, &s);
    s--;
    for (int i = 0; i < n; i++) scanf("%d\n", &train[i]);
    for (int i = 0; i < n; i++) scanf("%d\n", &revTrain[i]);

    if (!train[0]) { printf("NO"); return 0; }
    if (!train[s] && !revTrain[s]) { printf("NO"); return 0; }


    int i = 0;
    // foward
    while(i < n && i < s) {
        i++;
        while(i <= n && !train[i]) i++;
    }

    if (i == s) { printf("YES"); return 0; }

    while (i < n)
    {
        if (revTrain[i]) break;
        i++;
        while(i <= n && !train[i]) i++;
    }

    if (i >= n) { printf("NO"); return 0; }

    // backward
    while (i > -1 && i > s)
    {
        i--;
        while(i >= -1 && !revTrain[i]) i--;
    }

    if (i == s) { printf("YES"); return 0; }
    
}