#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

void showq(stack<int> gq)
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

    stack<int> tempArr;
    stack<int> stackArr;

    int arr[n] = {0};

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        // stackArr.push(input);
    }

    for (i = n - 1; i > -1; i--)
    {
        stackArr.push(arr[i]);
    }

    int a, b, j;

    while (stackArr.size() > 1)
    {
        int a = stackArr.top();
        stackArr.pop();
        int b = stackArr.top();

        // printf("-> %d : %d\n", a, b);
        // showq(stackArr);

        if ((a + b) % 2 == 0)
        {
            stackArr.pop();

            while (!tempArr.empty())
            {
                stackArr.push(tempArr.top());
                tempArr.pop();
            }

            // printf("--> ");
            // showq(stackArr);
        }
        else
            tempArr.push(a);
    }

    printf("%d", tempArr.size() + stackArr.size());
}