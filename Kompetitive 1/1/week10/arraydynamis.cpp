#include <stdio.h>
#include <stdlib.h>  // malloc
#include <string.h>  // memcpy, memset
#include <algorithm> // fill
using namespace std;

int main()
{
    int a[5]; // array statis -> stack mamory

    printf("%d\n", sizeof(a)); // keluar 20 byte (int size dikali 5)

    int n = 5;
    int *arr = (int *)malloc(sizeof(int) * n); // buat 4 * 5 byte pake heap memory

    printf("%d\n", sizeof(arr)); // keluar size dari pointer arr (8 byte)

    // malloc keluar void* (void pointer)

    int *arr3 = new int[n]; // cari c++ lebih lambat

    fill(arr3, arr3 + n, 1234);

    memset(arr, -1, sizeof(int) * n); // inisialisasi nilai arr 0 per byte paling cepat

    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = i * 10;
    // }

    int *arr2 = (int *)malloc(sizeof(int) * n);

    // printf("%d\n", sizeof(arr));

    memcpy(arr2, arr3, sizeof(int) * n); // copy arr to arr2 with low level

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}

// memset, memcpy itu sangat cepat