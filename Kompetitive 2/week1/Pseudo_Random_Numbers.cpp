#include <stdio.h>

int generateNum(int Z, int L, int I, int M);

int main()
{
    int Z, L, I, M;
    int tail, head, first;

    int indexTail, indexHead;

    int i, cycleStart, cycleLen, cases = 0;
    while (scanf("%d %d %d %d\n", &Z, &I, &M, &L) && Z != 0 && L != 0 && I != 0 && M != 0)
    {
        first = generateNum(Z, L, I, M);

        // printf("%d\n", first);

        tail = generateNum(Z, first, I, M);
        head = generateNum(Z, generateNum(Z, first, I, M), I, M);
        indexTail = 0;
        indexHead = 0;

        // printf("%d %d\n", tail, head);

        // step 1
        while (tail != head)
        {
            tail = generateNum(Z, tail, I, M);
            head = generateNum(Z, generateNum(Z, head, I, M), I, M);

            // printf("%d %d\n", tail, head);

            indexTail++;
            indexHead += 2;
        }

        i = indexHead / 2;

        // step 2
        indexHead = 0;
        head = first;

        while (head != head)
        {
            tail = generateNum(Z, tail, I, M);
            head = generateNum(Z, head, I, M);
            indexTail++;
            indexHead++;
        }

        cycleStart = indexHead;

        // step 3

        tail = generateNum(Z, head, I, M);
        indexTail = indexHead + 1;

        while (head != tail)
        {
            tail = generateNum(Z, tail, I, M);
            indexTail++;
        }

        cycleLen = indexTail;

        printf("Case %d: %d\n", cases + 1, cycleLen);
        cases++;
    }
}

int generateNum(int Z, int L, int I, int M)
{
    return (Z * L + I) % M;
}