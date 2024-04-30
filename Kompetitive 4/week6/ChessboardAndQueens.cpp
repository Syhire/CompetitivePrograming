#include <stdio.h>
#include <string.h>
using namespace std;

int n = 8;
bool map[10][10];
int count = 0;

bool col[10];
bool diag1[70];
bool diag2[70];

void solve(int y) {
    if (y == n) {
        count++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (map[i][y]) continue;
        if (col[i] || diag1[i + y] || diag2[i - y + n - 1]) continue;
        col[i] = diag1[i + y] = diag2[i - y + n - 1] = true;
        solve(y + 1);
        col[i] = diag1[i + y] = diag2[i - y + n - 1] = false;
    }
    
}

int main() {
    char input;
    memset(map, false, sizeof(bool) * 10 * 10);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf("%c\n", &input);
            if (input == '*') map[i][j] = true;
        }
    }
    
    solve(0);
    printf("%d\n", count);
}