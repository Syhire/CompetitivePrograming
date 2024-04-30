#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

long long n, q;
vector<int> v;

int main() {
    scanf("%lld %lld\n", &n, &q);

    long long arr[n + 10], pSumUp[n + 10], pSumDown[n + 10];
    pSumUp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld\n", &arr[i]);
        v.push_back(arr[i]);
        if (i > 0) pSumUp[i] = pSumUp[i - 1] + (arr[i] - arr[i - 1]) * i;
    }

    long long numBefore = arr[n - 1];
    long long num = arr[n - 1];
    pSumDown[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        num = arr[i];
        pSumDown[i] = pSumDown[i + 1] + (numBefore - num) * (n - i - 1);
        numBefore = num;
    }

    // for (int i = 0; i < n; i++)
    //     printf("%d ", pSumUp[i]);
    // printf("\n");
    // for (int i = 0; i < n; i++)
    //     printf("%d ", pSumDown[i]);
    // printf("\n");

    long long l, r;
    for (int i = 0; i < q; i++)
    { 
        scanf("%d %d\n", &l, &r);
        long long a = distance(v.begin(), lower_bound(v.begin(), v.end(), l) - 1);
        long long b = distance(v.begin(), upper_bound(v.begin(), v.end(), r));
        // printf("%d * %d, %d * %d\n", l - arr[a], a, arr[b] - r, n - b);
        long long res = 0;
        res += pSumUp[a] + (l - arr[a]) * (a + 1);
        res += pSumDown[b] + (arr[b] - r) * (n - b);
        printf("%lld\n", res);
    }
}