#include <stdio.h>

using namespace std;

// INI VARIABLE GLOBAL
int OFFSET = 100;

// INI CLASS Tcontoh YANG MEMILIKI METHOD jumlah()
class Contoh
{
public:
    int a, b;

    int jumlah();

    Contoh()
    {
        a = b = 0;
    };

    Contoh(int _a, int _b)
    {
        a = _a;
        b = _b;
        // this->b = _b;
    }

    ~Contoh()
    {
        printf("%d %d gone now\n", a, b);
    }
};

int jumlah();

int main()
{
    Contoh x;
    x.a = 5;
    x.b = 7;

    Contoh y(10, 20);
    int hasil = y.jumlah();

    printf("%d %d\n", x.jumlah(), jumlah());

    return 0;
}

// ISI METHOD jumlah() PUNYA CLASS Contoh
int Contoh::jumlah()
{
    return a + b + OFFSET; // boleh akses atribut & variable global
}

// ISI FUNCTION jumlah()
int jumlah()
{
    return 12345;
}