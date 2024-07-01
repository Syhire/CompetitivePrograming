#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);

    int k = (int) floor(log10(n) / log10(5));
    int sum = 0;

    for (int i = 1; i <= k; i++) 
        sum += (int) floor(n / pow(5.0, i));
    
    printf("%d\n", sum);
}