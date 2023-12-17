#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

class Node {
    public:
        int a;
        int b;
        int w;

        Node(){}
        Node(int _a, int _b, int _w) {
            a = _a;
            b = _b;
            w = _w;
        }

        bool operator<(Node const & bNode)
        {
            return w < bNode.w;
        }

};

int n, m;
vector<int> parent;
vector<Node> edge;
vector<bool> valid, inFirst;
bool isFirst;

int findSets(int element) {
    // printf("--> %d %d\n", element, parent[element]);
    if (element != parent[element])
        parent[element] = findSets(parent[element]);
    return parent[element];
}

int findMST() {
    parent.clear();
    for(int i = 0; i < n; i++) {
        parent.push_back(i);
    }

    int sets = n;
    int a, b, w;
    int sum = 0;

    for(int i = 0; i < m; i++) {
        if (valid[i]) {
            a = edge[i].a;
            b = edge[i].b;
            w = edge[i].w;


            if (findSets(a) != findSets(b)) {
                if (isFirst) inFirst[i] = true;
                parent[findSets(a)] = findSets(b);
                sets--;
                sum += w;
            }
        }
    }

    if (sets == 1) return sum;
    return -1;
}

int secMin() {
    int min = 1000000;

    for(int i = 0; i < m; i++) {
        if (inFirst[i] == true) {
            valid[i] = false;
            int temp = findMST();
            if (temp != -1 && temp < min) min = temp;
            valid[i] = true;
        }
    }

    return min;
}

int main() {
    int countCase;
    scanf("%d\n", &countCase);

    while (countCase--)
    {
        edge.clear();
        scanf("%d %d\n", &n, &m);

        int a, b, c;
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d\n", &a, &b, &c);
            edge.push_back(Node(a - 1, b - 1, c));
        }

        sort(edge.begin(), edge.end());

        inFirst.assign(m, 0);
        valid.assign(m, 1);

        isFirst = true;
        int first = findMST();
        
        isFirst = false;
        int second = secMin();

        printf("%d %d\n", first, second);
    }
}