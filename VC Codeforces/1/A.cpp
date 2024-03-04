#include <stdio.h>
#include <limits.h>

int main() {
    int loop;

    scanf("%d\n", &loop);

    while (loop--)
    {
        int n;
        int minN = INT_MAX, maxN = -1;

        scanf("%d\n", &n);
        char input;

        for (int i = 0; i < n; i++)
        {
            scanf("%c\n", &input);
            if (input == 'B') {
                if (minN > i) minN = i;
                if (maxN < i) maxN = i;
            }
        }

        printf("%d\n", maxN - minN + 1);
    }
}