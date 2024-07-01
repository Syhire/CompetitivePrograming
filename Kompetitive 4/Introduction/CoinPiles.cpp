#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t;
    scanf("%d\n", &t);

    long a, b;
    while (t--)
    {
        scanf("%ld %ld\n", &a, &b);
    
        if ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b))
            printf("YES\n");
        else
            printf("NO\n");
    }
}