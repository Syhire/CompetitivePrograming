#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int N, t, i, j;

unsigned int numOne = 7777;

string testSatu(unsigned int arr[])
{
    unsigned int sum = 0;
    for (i = 0, j = N - 1; i != j;)
    {
        sum = arr[i] + arr[j];
        if (sum == numOne)
            return "Yes";
        else if (sum > numOne)
            j--;
        else
            i++;
    }

    return "No";
}

string testDua(unsigned int arr[])
{
    for (i = 0, j = N - 1; i < N / 2; i++, j--)
        if (arr[i] == arr[i + 1] || arr[j] == arr[j - 1])
            return "Contains duplicate";

    return "Unique";
}

long long testTiga(unsigned int arr[])
{
    int sum = 1;

    for (i = 0; i < N; i++)
    {
        if (arr[i] == arr[i + 1])
            sum++;
        else
            sum = 1;

        if (sum > (N / 2))
        {
            return arr[i];
        }
    }

    return -1;
}

int testEmpat(unsigned int arr[])
{
    if (N % 2 == 1)
        return printf("%u", arr[N / 2]);
    else
        return printf("%u %u", arr[(N / 2) - 1], arr[N / 2]);
}

int testLima(unsigned int arr[])
{
    for (i = 0; i < N && arr[i] <= 999; i++)
    {
        if (arr[i] < 100)
            continue;

        printf("%u ", arr[i]);
    }

    return 1;
}

int test(unsigned int arr[])
{
    switch (t)
    {
    case 1:
        return printf("%s", testSatu(arr).c_str());
    case 2:
        return printf("%s", testDua(arr).c_str());
    case 3:
        return printf("%lld", testTiga(arr));
    case 4:
        return testEmpat(arr);
    default:
        return testLima(arr);
    }
}

int main()
{
    scanf("%d %d\n", &N, &t);

    unsigned int arr[N + 1] = {0};

    for (i = 0; i < N; i++)
        scanf("%u", &arr[i]);

    sort(arr, arr + N);

    return test(arr);
}