#include <stdio.h>
#include <math.h>
using namespace std;

long long n;
long long arr[55];
long long pow2[55];

void calc(int bits) {
    arr[1] = 1;
    pow2[1] = 1;
    for (int i = 2; i <= bits; i++) {
        pow2[i] = pow2[i - 1] * 2;
        arr[i] = 2 * arr[i - 1] + pow2[i];
    }
}


int main() {
    scanf("%lld", &n);

    long long howmanybit = (long long) log2l(n) + 1;
    // printf("bits: %lld\n\n", howmanybit);
    calc(howmanybit);

    // if n is power of 2
    if (((n + 1) & ((n + 1) - 1)) == 0) {
        printf("%lld\n", arr[howmanybit]);
        return 0;
    };

    // for (int i = 1; i <= howmanybit; i++)
    // {
    //     printf("%llu\n", arr[i]);
    // }
    // printf("\n");

    int currBit = howmanybit - 1;
    int currHead = 0;
    long long res = 0;
    long long end = ((long long) 1 << howmanybit) - 1;
    long long start = 0;

    while (start != end)
    {
        long long middle = (start + end) / 2;
        printf("%lld - %lld - %lld : %lld + %d * (%lld) = %lld, [%s]\n", start, middle, end, 
            arr[currBit], currHead, (middle - start + 1),
            arr[currBit] + currHead * (middle - start + 1), middle > n ? "no":"yes");

        if (middle > n) {
            end = middle;
        } else {
            res += arr[currBit] + currHead * (middle - start + 1);
            start = middle + 1;
            currHead++;
        }
        currBit--;
    }
    
    printf("%lld\n", res);
}