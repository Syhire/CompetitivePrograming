#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;

int n, m, input;
multiset<int> arr;

int main() {
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &input);
        arr.insert(input);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d\n", &input);

        multiset<int>::iterator n = arr.upper_bound(input);
        if (n == arr.begin()) {
            printf("-1\n");
            continue;
        }
        n--;
        printf("%d\n", *n);
        arr.erase(n);
    }
}