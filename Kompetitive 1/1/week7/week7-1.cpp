#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int loop, n, i, j;
    scanf("%d\n", &loop);

    int a;
    char b;

    for (i = 0; i < loop; i++)
    {
        printf("Case #%d: ", i + 1);

        scanf("%d\n", &n);

        int idxB = 0;
        int idxR = 0;

        int B[n] = {0};
        int R[n] = {0};
        int sum = 0;

        for (j = 0; j < n; j++)
        {
            scanf("%d%c\n", &a, &b);

            if (b == 'B')
            {
                B[idxB] = a;
                idxB++;
            }
            else
            {
                R[idxR] = a;
                idxR++;
            }
        }

        sort(B, B + idxB + 1, greater<int>());
        sort(R, R + idxR + 1, greater<int>());

        for (j = 0; j < idxB && j < idxR; j++)
        {
            // printf("%d %d\n", B[j], R[j]);
            sum += B[j] + R[j] - 2;
        }

        printf("%d\n", sum);
    }
}