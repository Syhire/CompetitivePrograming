#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int i, n, com, input;

    bool isStack, isQueue, isPQueue;

    while (scanf("%d\n", &n) != EOF)
    {
        isStack = true, isQueue = true, isPQueue = true;
        stack<int> stackArr;
        queue<int> queueArr;
        priority_queue<int> pQueueArr;

        for (i = 0; i < n; i++)
        {
            scanf("%d %d\n", &com, &input);
            if (com == 1)
            {
                stackArr.push(input);
                queueArr.push(input);
                pQueueArr.push(input);
            }
            else
            {
                if (stackArr.empty() || stackArr.top() != input)
                    isStack = false;
                if (queueArr.empty() || queueArr.front() != input)
                    isQueue = false;
                if (pQueueArr.empty() || pQueueArr.top() != input)
                    isPQueue = false;

                if (!stackArr.empty())
                    stackArr.pop();
                if (!queueArr.empty())
                    queueArr.pop();
                if (!pQueueArr.empty())
                    pQueueArr.pop();
            }
        }

        int sum = isStack + isQueue + isPQueue;

        if (sum > 1)
            printf("not sure");
        else if (isStack)
            printf("stack");
        else if (isQueue)
            printf("queue");
        else if (isPQueue)
            printf("priority queue");
        else
            printf("impossible");

        printf("\n");
    }
}