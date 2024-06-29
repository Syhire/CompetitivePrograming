#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, a, b;

int main() {
    scanf("%d %d\n", &n, &m);
    while (m--)
    {
        scanf("%d %d\n", &a, &b);
        printf("%d %d\n", min(a, b), max(a, b));
        
    }
}