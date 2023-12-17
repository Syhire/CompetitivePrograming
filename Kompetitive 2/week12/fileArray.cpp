#include <stdio.h>
using namespace std;

int main() {
    // char buffer[10000];
    // FILE *fi = fopen("foo.bin", "rb");
    FILE *fo = fopen("foo.bin", "wb");

    int x[5] = {10, 11, 12, 1, 5};
    // fscanf(fi, "%d", &x);
    // printf("%d", x);

    fwrite(x, sizeof(int), 5, fo);
    // fread(x, sizeof(int), 5, fi);

    // fclose(fi);
    // fclose(fo);
}

// btye: fread, fwrite
// text: fscanf, fprintf