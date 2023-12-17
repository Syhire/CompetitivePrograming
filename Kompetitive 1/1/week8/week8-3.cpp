#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

void show(stack<int> gq)
{
    stack<int> g = gq;
    while (!g.empty())
    {
        printf("%d ", g.top());
        g.pop();
    }
    printf("\n");
}

int main()
{
    int i, n, input;

    scanf("%d", &n);

    n *= 2;

    int arr[n] = {0};
    int sum = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum ^= arr[i];
    }

    if (sum != 0)
    {
        printf("impossible");
        return 0;
    }

    int count = 1;

    stack<int> stackArr;
    stack<int> stackArr2;

    for (i = n - 1; i > -1; i--)
    {
        stackArr.push(arr[i]);
    }

    stackArr2.push(stackArr.top());
    stackArr.pop();

    while (!stackArr.empty())
    {
        if (stackArr2.top() == stackArr.top())
        {
            stackArr2.pop();
            stackArr.pop();

            if (!stackArr.empty())
            {
                stackArr2.push(stackArr.top());
                stackArr.pop();
                count++;
            }
        }
        else
        {
            stackArr2.push(stackArr.top());
            stackArr.pop();
        }

        count++;
    }

    printf("%d", count);
}
