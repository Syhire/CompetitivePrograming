#include <stdio.h>
#include <string.h>
using namespace std;

class Wombat
{
public:
    char *nama;
    int umur;

    Wombat()
    {
    }
};

char *foo()
{
    char *result = new char[100];
    strcpy(result, "Hello World");
    return result;
}

int main()
{
    Wombat a;
    a.nama = foo();
    printf("%s\n", a.nama);
}