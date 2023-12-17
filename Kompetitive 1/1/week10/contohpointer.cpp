#include <stdio.h>

int main()
{
    int a = 0x0000000000000000000BC614E; // 00 BC 61 4E pakai hex
    a = 057060516;                       // 57 060 516 pakai octa
    int *p = &a;

    char *p2 = (char *)&a;
    char c = (char)a;

    printf("%X\n", *(p2));
    printf("%X\n", *(p2 + 1));
    printf("%X\n", *(p2 + 2));
    printf("%X\n", *(p2 + 3));

    return 0;
}