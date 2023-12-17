#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int N = 140;
    int a = 2;
    for (int i = 0; i < 40; i++)
        printf("(%d, '%c'),\n", (rand() % N) + 1, (rand() % a) ? 'a' : 'c');
}