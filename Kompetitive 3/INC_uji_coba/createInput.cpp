#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    printf("100000\n");
    // printf("1000000\n");

    for (int i = 0; i < 100000 - 1; i++)
    {
        printf("1000 ");
        // printf("%d ", rand() % 4001);
    }

    printf("\n");
    for (int i = 0; i < 100000; i++)
    {
        printf("0 ");
        // printf("%d ", rand() % 4001);
    }
    printf("\n");
    for (int i = 0; i < 100000 - 1; i++)
    {
        printf("0 ");
        // printf("%d ", rand() % 4001);
    }
    printf("100000\n");
}