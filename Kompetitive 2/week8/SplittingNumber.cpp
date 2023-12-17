#include <stdio.h>
#include <bitset>
#include <string.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d\n", &n) && n != 0)
    {
        bitset<32> input(n);

        char strInput[50];
        strcpy(strInput, input.to_string().c_str());

        bitset<32> a;
        bitset<32> b;
        bitset<32> setter(1);

        bool isOnA = true;

        for(int i = 31; i > -1; i--) {
            if (strInput[i] == '1') {
                if (isOnA) a |= setter;
                else b |= setter;

                isOnA = !isOnA;
            }
            setter <<= 1;
        }

        printf("%ld %ld\n", a.to_ulong(), b.to_ulong());
    }

}
