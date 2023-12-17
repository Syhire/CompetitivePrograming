#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int i, n, input;

    scanf("%d", &n);

    stack<int> stackArr;
    queue<int> queueArr;

    int sum = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &input);
        stackArr.push(input);
        sum ^= input;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &input);
        queueArr.push(input);
        sum ^= input;
    }

    if (sum != 0)
    {
        printf("impossible");
        return 0;
    }

    while (!queueArr.empty() && !stackArr.empty())
    {
        if (queueArr.front() != stackArr.top())
        {
            printf("impossible");
            return 0;
        }
        stackArr.pop();
        queueArr.pop();
    }

    printf("%d", n * 2);
}
