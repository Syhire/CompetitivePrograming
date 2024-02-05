#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;  

vector<pair<int, int> > edge[10010]; // node, weight

pair<int, int> bfs(int start) {
    pair<int, int> maxHasil = make_pair(-1, INT_MIN); // node, weight
    int hasil[10010];
    bool visited[10010];

    for (int i = 0; i < 10010; i++)
    {       
        hasil[i] = INT_MAX;
        visited[i] = false;
    }

    queue<int> q; // node
    hasil[start] = 0;
    q.push(start);
    
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // printf("=> %d\n", front);

        for (int i = 0; i < edge[front].size(); i++)
        {
            pair<int, int> next = edge[front][i];

            // printf("==> %d [%d]\n", next.first, next.second);
            // printf("=== %d > %d\n", hasil[next.first], next.second + hasil[front]);

            if (hasil[next.first] > next.second + hasil[front]) {
                hasil[next.first] = next.second + hasil[front];
                if (hasil[next.first] > maxHasil.second) maxHasil = make_pair(next.first, hasil[next.first]);
                q.push(next.first);
            }
        }
    }
    
    return maxHasil;
}

int main() {
    char str[50];
    while (fgets (str , 50 , stdin) != NULL)
    {
        for (int i = 0; i < 10010; i++) edge[i].clear();
        
        int a, b, w;
        // get roads
        do {
            sscanf(str, "%d %d %d", &a, &b, &w);
            // printf("- %d %d %d\n", a, b, w);
            edge[a].push_back(make_pair(b, w));
            edge[b].push_back(make_pair(a, w));
        } while (fgets (str , 50 , stdin) != NULL && str[0] != 10);
        
        // printf("### END ###\n");
        pair<int, int> res = bfs(1);
        pair<int, int> res2 = bfs(res.first);
        printf("%d\n", res2.second);
    }
}