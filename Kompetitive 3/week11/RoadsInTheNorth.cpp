#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<int, vector<pair<int, int> > > edge;

int main()
{
    // get tree
    int x, y, dis;
    while (scanf("%d %d %d\n", &x, &y, &dis) != EOF)
    {
        edge[x].push_back(make_pair(y, dis));
        edge[y].push_back(make_pair(x, dis));
    }
}