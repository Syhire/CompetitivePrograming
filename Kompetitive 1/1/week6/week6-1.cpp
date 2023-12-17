#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int N, t, i;

    scanf("%d %d\n", &N, &t);

    if (t == 1)
    {
        printf("7");
    }

    unsigned int arr[N + 1] = {0};

    for (i = 0; i < N; i++)
        scanf("%u", &arr[i]);

    if (t == 2)
    {
        if (arr[0] > arr[1])
            printf("Bigger");
        else if (arr[0] == arr[1])
            printf("Equal");
        else
            printf("Smaller");
    }

    else if (t == 3)
    {
        sort(arr, arr + 3);

        printf("%d", arr[1]);
    }

    else if (t == 4)
    {
        unsigned long long sum = 0;
        for (i = 0; i < N; i++)
            sum += arr[i];

        printf("%llu", sum);
    }

    else if (t == 5)
    {
        unsigned long long sum = 0;
        for (i = 0; i < N; i++)
            if (arr[i] % 2 == 0)
                sum += arr[i];

        printf("%llu", sum);
    }

    else if (t == 6)
    {
        for (i = 0; i < N; i++)
            printf("%c", 'a' + (arr[i] % 26));
    }

    else if (t == 7)
    {
        unsigned int index = 0;
        bool isDone = false;
        for (i = 0; i < N; i++)
        {
            index = arr[index];
            if (index >= N)
            {
                printf("Out");
                isDone = true;
                break;
            }
            else if (index == N - 1)
            {
                printf("Done");
                isDone = true;
                break;
            }
        }

        if (!isDone)
            printf("Cyclic");
    }
}