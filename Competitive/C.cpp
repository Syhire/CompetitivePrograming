#include <stdio.h>

using namespace std;

int n, r, k;

int main() {
    scanf("%d %d %d\n", &n, &r, &k);

    int bobot[1010];
    int bagian[1010];
    int sum = 0;
    for (int i = 0; i < n; i++)
        scanf("%d\n", &bobot[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d\n", &bagian[i]);
        sum += bobot[i] / 100 * bagian[i];
    }
    
    printf(sum >= r ? "PASS" : "NOT PASS");
    return 0;
}