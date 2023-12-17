#include <stdio.h>
#include <stdlib.h>  // malloc
#include <string.h>  // memcpy, memset
#include <algorithm> // fill
using namespace std;

void foo(int **x)
{
    printf("%d", x[2][3]);
}

int main()
{
    int i;

    // === PAKAI C++ NEW ===

    int **arr = new int *[5];

    for (i = 0; i < 5; i++)
        arr[i] = new int[10];

    for (i = 0; i < 5; i++)
        delete[] arr[i];
    delete[] arr;

    // === PAKAI MALLOC ===

    // int *a = (int *)malloc(sizeof(int) * 10);
    int **a = (int **)malloc(sizeof(int *) * 10); // dynamis 2d array with malloc

    for (i = 0; i < 10; i++)
        a[i] = (int *)malloc(sizeof(int *) * 20);

    // ...

    // membebaskan memory dari a
    for (i = 0; i < 10; i++)
        free(a[i]);

    free(a);

    return 0;
}