#include <stdio.h>
#include <vector>
using namespace std;

int n, m;
vector<int> edge[100010];

int main() {
    scanf("%d %d\n", &n, &m);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d\n", &a, &b);
        edge[a].push_back(b);
    }
    
    
}