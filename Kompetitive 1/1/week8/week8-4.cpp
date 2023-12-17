#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    int count, i;
    scanf("%d\n", &count);

    stack<char> stackArr;
    char input;

    int countOpeing = 0;

    for (i = 0; i < count; i++)
    {
        // printf("%d", i);
        scanf("%c", &input);

        if (input == ' ')
            continue;

        if (input == 40 || input == 91 || input == 123)
        {
            stackArr.push(input);
            countOpeing++;
        }

        if (!stackArr.empty())
        {
            if (input == 41) // )
                if (stackArr.top() == 40)
                {
                    stackArr.pop();
                    countOpeing--;
                }
                else
                {
                    printf(") %d", i);
                    return 0;
                }

            if (input == 93) // ]
                if (stackArr.top() == 91)
                {
                    stackArr.pop();
                    countOpeing--;
                }
                else
                {
                    printf("] %d", i);
                    return 0;
                }

            if (input == 125) // }
                if (stackArr.top() == 123)
                {
                    stackArr.pop();
                    countOpeing--;
                }
                else
                {
                    printf("} %d", i);
                    return 0;
                }
        }
        else
        {
            if (input == 41)
                printf(") %d", i);
            else if (input == 93)
                printf("] %d", i);
            else if (input == 125)
                printf("} %d", i);
            return 0;
        }
    }

    // printf("outside %d %d\n", countOpeing, i);

    if (i == count && countOpeing >= 0)
        printf("ok so far");
}