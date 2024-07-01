#include <stdio.h>
#include <string.h>
using namespace std;

char arr[510];

int main()
{
    int t;
    scanf("%d\n", &t);

    while (t--)
    {
        scanf("%s\n", arr);
        bool taken = false;
        int idx = 0;

        while (arr[idx] == '1')
            idx++;

        int sum = 1;
        if (idx != 0 && idx < strlen(arr) && arr[idx] != arr[idx - 1])
            sum++;

        // printf("# %d\n", idx);

        for (int i = idx + 1; i < strlen(arr); i++)
        {
            if (arr[i - 1] != arr[i])
            {
                if (!taken)
                    taken = true;
                else
                    sum++;
            }
        }

        printf("%d\n", sum);
    }
}