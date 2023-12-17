#include <stdio.h>
using namespace std;

int main() {
    char buffer[10000];
    FILE *fi = fopen("foo.bin", "rb");
    FILE *fo = fopen("foo2.bin", "wb");

    // fscanf(fi, "%d", &x);
    // printf("%d", x);

    // fwrite(&x, sizeof(int), 1, fo);
    // fread(&x, sizeof(int), 1, fi);

    // printf("%d\n", x);

    int x;

    // x = fread(buffer, sizeof(char), 10000, fi);
    // while (x)
    // {
    //     /* code */
    //     fwrite(buffer, sizeof(char), x, fo);
    //     x = fread(buffer, sizeof(char), 10000, fi);
    // }

    while (x = fread(buffer, sizeof(char), 10000, fi) && x)
    {
        /* code */
        fwrite(buffer, sizeof(char), x, fo);
    }
    

    // fclose(fi);
    // fclose(fo);
}

// btye: fread, fwrite
// text: fscanf, fprintf