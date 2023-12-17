#include <stdio.h>
using namespace std;

int main() {
    int t;
    scanf("%d\n", &t);

    while (t--)
    {
        int n;
        scanf("%d\n", &n);

        int arr[50];
        int max = -1;
        int imax = -1;

        for(int i = 0 ; i < n; i++) {
            scanf("%d\n", &arr[i]);
            if (arr[i] > max) {
                max = arr[i];
                imax = i;
            }
        }

        printf("%d\n", imax + 1);
    }
    
}