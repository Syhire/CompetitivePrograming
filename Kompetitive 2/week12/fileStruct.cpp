#include <stdio.h>
using namespace std;

class Foo {
    public:
        int a;
        double b;

        Foo() {}
        Foo(int _a, double _b) {
            a = _a;
            b = _b;
        }
};


// harus sama bentuknya
class Abc {
    public:
        int a;
        double b;

        Abc() {}
        Abc(int _a, double _b) {
            a = _a;
            b = _b;
        }
};

int main() {
    // write
    // Foo x[3] = {Foo(1, 2.5), Foo(10, 11.5), Foo(1000, 4000)};
    // FILE *fo = fopen("foo.bin", "wb");

    // fwrite(x, sizeof(Foo), 3, fo);


    // read
    // Abc x[100];

    // FILE *fi = fopen("foo.bin", "rb");
    // int n = fread(x, sizeof(Abc), 100, fi);

    // for(int i = 0; i < n; i++) {
    //     printf("%d = a: %d, b: %f\n", i, x[i].a, x[i].b);
    // }
}