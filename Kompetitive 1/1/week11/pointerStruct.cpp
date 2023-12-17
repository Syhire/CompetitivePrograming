#include <stdio.h>
#include <string.h>
using namespace std;

class Contoh
{
public:
    char nama[50];

    Contoh()
    {
        strcpy(nama, "Dr. Wombat");
        printf("Welcome %s\n", nama);
    };

    ~Contoh()
    {
        printf("Goodbye %s\n", nama);
    }
};

int jumlah();

int main()
{
    Contoh x;

    printf("lalalalala\n");

    return 0;
}