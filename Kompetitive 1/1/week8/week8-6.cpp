#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int count, countIdx;

    scanf("%d", &count);

    int n;

    unsigned int p, q, seq;

    stack<bool> stackArr;

    for (countIdx = 0; countIdx < count; countIdx++)
    {
        scanf("%d %d/%d\n", &n, &seq);

        p = 1;
        q = 1;

        while (seq > 1)
        {
            if (seq % 2 == 1)
            {
                seq--;
                stackArr.push(true);
            }
            else
                stackArr.push(false);

            seq /= 2;
        }

        while (!stackArr.empty())
        {
            if (stackArr.top())
                p = p + q;
            else
                q = p + q;

            stackArr.pop();
        }

        printf("%d %u/%u\n", n, p, q);
    }
}