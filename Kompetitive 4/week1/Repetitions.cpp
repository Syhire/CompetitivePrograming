#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int maxN = -1, n = 1;
    char input, curr = '0';
    while (scanf("%c\n", &input) != EOF)
    {
        if (input == curr)
        {
            n += 1;
        }
        else
        {
            curr = input;
            n = 1;
        }
        maxN = max(maxN, n);
    }

    printf("%d\n", maxN);
}