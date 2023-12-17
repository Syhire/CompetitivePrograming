#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int N, t, i, j;

    scanf("%d %d\n", &N, &t);

    unsigned int arr[N + 1] = {0};

    for (i = 0; i < N; i++)
        scanf("%u", &arr[i]);

    sort(arr, arr + N);

    if (t == 1)
    {
        bool done = false;
        unsigned int sum = 0;
        unsigned int num = 7777;
        for (i = 0, j = N - 1; i != j;)
        {
            sum = arr[i] + arr[j];
            if (sum == num)
            {
                printf("Yes");
                done = true;
                break;
            }
            else if (sum > num)
                j--;
            else
                i++;
        }

        if (!done)
            printf("No");
    }
    else if (t == 2)
    {
        bool done = false;

        for (i = 0, j = N - 1; i < N / 2; i++, j--)
        {
            if (arr[i] == arr[i + 1] || arr[j] == arr[j - 1])
            {
                done = true;
                printf("Contains duplicate");
                break;
            }
        }

        if (!done)
            printf("Unique");
    }
    else if (t == 3)
    {
        int sum = 1;
        bool done = false;

        for (i = 0; i < N; i++)
        {
            if (arr[i] == arr[i + 1])
                sum++;
            else
                sum = 1;

            if (sum > (N / 2))
            {
                printf("%u", arr[i]);
                done = true;
                break;
            }
        }

        if (!done)
            printf("-1");
    }
    else if (t == 4)
    {
        if (N % 2 == 1)
        {
            printf("%u", arr[N / 2]);
        }
        else
        {
            printf("%u %u", arr[(N / 2) - 1], arr[N / 2]);
        }
    }
    else if (t == 5)
    {
        for (i = 0; i < N && arr[i] <= 999; i++)
        {
            if (arr[i] < 100)
                continue;

            printf("%u ", arr[i]);
        }
    }

    return 0;
}