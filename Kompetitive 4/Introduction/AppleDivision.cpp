#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int n;
int arr[30];
long long minN = LLONG_MAX;
bool rek[30];

void solve(int num) {
    if (num == n) {
        long long sum1 = 0;
        long long sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            // printf("%d", rek[i]);
            if (rek[i]) sum1 += arr[i];
            else sum2 += arr[i];
        }
        minN = min(minN, abs(sum1 - sum2));
        // printf("\n");
    }
    else {
        rek[num] = 0;
        solve(num + 1);
        rek[num] = 1;
        solve(num + 1);
    }
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        scanf("%d\n", &arr[i]);
    
    solve(0);
    printf("%lld\n", minN);
}