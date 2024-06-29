#include <stdio.h>

using namespace std;

int n = 0;
int arr[20];
bool test[20] = {true};

void solve(int num)
{
    if (num == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    else
    {
        if (test[num])
        {
            arr[num] = 0;
            solve(num + 1);
            arr[num] = 1;
            solve(num + 1);
        } else {
            arr[num] = 1;
            solve(num + 1);
            arr[num] = 0;
            solve(num + 1);
        }
        test[num] = !test[num];
    }
}

int main()
{
    scanf("%d\n", &n);
    solve(0);
}