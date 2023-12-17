#include <stdio.h>

void foo(int *p) // passing by reference
{
    *p = *p + 10;
    printf("%d\n", *p);
}

void foo2(int x) // passing by value
{
    x = x + 10;
    printf("%d\n", x);
}

void foo3(int &x) // passing by reference (ga usah pake aja)
{
    x = x + 10;
    printf("%d\n", x);
}

int main()
{
    int angka = 100;
    foo(&angka);
    foo2(angka); // angka tidak berubah
    foo3(angka);
    printf("angka: %d\n", angka);
    return 0;
}