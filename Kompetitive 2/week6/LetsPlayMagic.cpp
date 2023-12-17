#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    int n;
    char empty = '_';
    char input1[5], input2[20];
    string arr[55];

    while (scanf("%d\n", &n) && n != 0)
    {
        int idx = -1;
        fill(arr, arr + 55, empty);

        int count = n;
        while (count--)
        {
            scanf("%s %s\n", input1, input2);
            string input = input1;
            int len = strlen(input2);

            while (len > 0)
            {
                idx = (idx + 1) % n;

                if ((arr[idx].c_str()[0]) == empty)
                    len--;
            }

            arr[idx] = input;
        }

        for (int i = 0; i < n; i++)
        {
            printf("%s", arr[i].c_str());
            if (i != n - 1)
                printf(" ");
        }

        printf("\n");
    }
}