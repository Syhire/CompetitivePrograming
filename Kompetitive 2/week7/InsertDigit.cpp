#include <stdio.h>

char arr[200010];

int main()
{
    int count, n, d;
    scanf("%d\n", &count);
    while (count--)
    {
        scanf("%d %d\n", &n, &d);
        scanf("%s\n", arr);

        // printf("-\n");

        if (d == 0) {
            printf("%s0\n", arr);
            continue;
        } else if (d == 9) {
            printf("9%s\n", arr);
            continue;
        }

        // printf("%s\n", arr);

        bool isDone = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] - '0' < d && !isDone) {
                isDone = true;
                printf("%d", d);
            };

            printf("%c", arr[i]);
        }

        if (!isDone) printf("%d", d);
        printf("\n");
    }
}