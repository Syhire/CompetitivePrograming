#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

bool sum;
int n;
vector<int> arr[210];
int colors[210];

void DFS(int i, int color)
{
    if (colors[i] != 0) {
        if (color != colors[i]) sum = false;
    } else {
        colors[i] = color;

        for(int j = 0; j < arr[i].size(); j++) {
            DFS(arr[i][j], (color == 1) ? 2 : 1);
        }

    }
}

int main()
{
    while (scanf("%d\n", &n) && n != 0)
    {
        for(int i = 0; i < n + 10; i++) arr[i].clear();
        memset(colors, 0, sizeof(colors));

        int count, edge1, edge2;
        scanf("%d\n", &count);

        for (int i = 0; i < count; i++) {
            scanf("%d %d\n", &edge1, &edge2);

            arr[edge1].push_back(edge2);
            arr[edge2].push_back(edge1);
        }

        sum = true;
        DFS(0, 1);

        printf("%s\n", sum ? "BICOLORABLE." : "NOT BICOLORABLE.");
    }

    return 0;
}