#include <stdio.h>

int k;

int calcFib(int *fibonacci, int n)
{
    // printf("%d\n", n);
    fibonacci[n] = (fibonacci[n - 1] + fibonacci[n - 2]) % k;
    return fibonacci[n];
}

int main()
{
    int q;
    scanf("%d", &q);

    int idxT = 2;
    int idxH = 2;

    printf("%d\n", q);

    for (int loop = 0; loop < q; loop++)
    {
        scanf("%d", &k);

        int fibonacci[10000];
        fibonacci[0] = 1;
        fibonacci[1] = 1;

        calcFib(fibonacci, 2);
        int first = fibonacci[2];

        idxT++;
        idxH += 2;
        calcFib(fibonacci, idxH - 1);
        calcFib(fibonacci, idxH);

        int hare = fibonacci[idxH];
        int tortoise = fibonacci[idxT];

        while (tortoise != hare)
        {
            // printf("a");
            idxT++;
            idxH += 2;
            calcFib(fibonacci, idxH - 1);
            calcFib(fibonacci, idxH);

            hare = fibonacci[idxH];
            tortoise = fibonacci[idxT];
        }

        int mu = 0;
        hare = first;
        int countMax = idxH;
        idxH = 2;

        while (tortoise != hare)
        {
            // printf("b");
            idxT++;
            idxH++;
            if (idxT > countMax)
                calcFib(fibonacci, idxT);

            tortoise = fibonacci[idxT];
            hare = fibonacci[idxH];
            mu++;
        }

        int lambda = 1;
        idxH = idxT + 1;
        hare = fibonacci[idxH];

        while (tortoise != hare)
        {
            // printf("c");
            idxH++;
            hare = fibonacci[idxH];
            lambda++;
        }

        printf("%d\n", lambda);
    }
}
