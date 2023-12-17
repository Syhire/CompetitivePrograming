#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int loop, i;

    scanf("%d\n", &loop);

    char a[51], b[51];

    int xA, xB;

    char typeA, typeB;

    string strA, strB;

    for(i = 0; i < loop; i++) {
        scanf("%s %s\n", a, b);

        strA = a;
        strB = b;

        xA = count(strA.begin(), strA.end(), 'X');
        xB = count(strB.begin(), strB.end(), 'X');

        typeA = a[strA.length() - 1];
        typeB = b[strB.length() - 1];

        // S : 83, M : 77, L : 76
        if (typeA > typeB)
            printf("<");
        else if (typeA < typeB)
            printf(">");
        else
            if (xA == xB)
                printf("=");
            else if (typeA == 'S')
                if (xA > xB)
                    printf("<");
                else
                    printf(">");
            else if (typeA == 'L')
                if (xA > xB)
                    printf(">");
                else
                    printf("<");
        printf("\n");
    }   
}