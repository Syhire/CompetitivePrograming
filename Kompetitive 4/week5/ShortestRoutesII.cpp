#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m, q;
long long dist[510][510];

long long INFs = 0x3f3f3f3f3f3f3f3f;

void calc() {
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
            
        }
        
    }
    
}

int main() {
    scanf("%d %d %d\n", &n, &m, &q);
    int a, b;
    long long c;

    memset(dist, 0x3f, sizeof(long long) * 510 * 510);

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %lld\n", &a, &b, &c);
        a--; b--;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    calc();

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d\n", &a, &b);
        a--; b--;
        if (dist[a][b] == INFs)
            printf("-1\n");
        else
            printf("%lld\n", dist[a][b]);
    }
    
}