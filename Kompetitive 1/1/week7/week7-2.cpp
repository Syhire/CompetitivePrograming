#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
// work
int main()
{
    int p, n;
    scanf("%d %d\n", &p, &n);

    int i, q, j = 0;
    string arr[p];
    char str[21];

    for (i = 0; i < n; i++)
    {
        scanf("%s", str);
        bool isThere = false;

        for (q = 0; q < j; q++)
        {
            if (strcmp(arr[q].c_str(), str) == 0)
            {
                isThere = true;
                break;
            }
        }

        if (!isThere)
        {
            arr[j] = str;
            j++;
        }

        if (j == p)
        {
            printf("%d", i + 1);
            return 0;
            break;
        }
    }

    printf("paradox avoided");
}