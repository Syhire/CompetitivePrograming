#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int N, t, i;

string testDua(unsigned int arr[])
{
    if (arr[0] > arr[1])
        return "Bigger";
    else if (arr[0] == arr[1])
        return "Equal";
    else
        return "Smaller";
}

unsigned int testTiga(unsigned int arr[])
{
    sort(arr, arr + 3);

    return arr[1];
}

unsigned long long testEmpat(unsigned int arr[])
{
    unsigned long long sum = 0;
    for (i = 0; i < N; i++)
        sum += arr[i];

    return sum;
}

unsigned long long testLima(unsigned int arr[])
{
    unsigned long long sum = 0;
    for (i = 0; i < N; i++)
        if (arr[i] % 2 == 0)
            sum += arr[i];

    return sum;
}

// gatau caranya wkwk
int testEnam(unsigned int arr[])
{
    for (i = 0; i < N; i++)
        printf("%c", 'a' + (arr[i] % 26));

    return 0;
}

string testTujuh(unsigned int arr[])
{
    unsigned int index = 0;

    for (i = 0; i < N; i++)
    {
        index = arr[index];

        if (index >= N)
            return "Out";
        else if (index == N - 1)
            return "Done";
    }

    return "Cyclic";
}

int test(unsigned int arr[])
{
    string res;

    switch (t)
    {
    case 2:
        return printf("%s", testDua(arr).c_str());
    case 3:
        return printf("%u", testTiga(arr));
    case 4:
        return printf("%llu", testEmpat(arr));
    case 5:
        return printf("%llu", testLima(arr));
    case 6:
        return testEnam(arr);
    case 7:
        return printf("%s", testTujuh(arr).c_str());
    default:
        return printf("7");
    }
}

int main()
{
    scanf("%d %d\n", &N, &t);

    unsigned int arr[N + 1] = {0};

    for (i = 0; i < N; i++)
        scanf("%u", &arr[i]);

    return test(arr);
}