#include <stdio.h>
#include <stack>

using namespace std;

int n;
char text[10010];
char input[10010];
stack<char> s;

void emptyStack()
{
    while (!s.empty())
        s.pop();
}

bool isPossible()
{
    int i = 0;
    int j = n - 1;

    int sum = 0;

    while (j >= 0)
    {
        printf("%c\n", text[j]);
        s.push(text[j--]);
        sum++;

        if (!s.empty() && s.top() == input[i])
            for (int l = 0; l < sum; l++)
            {
                // printf("%d %c == %c\n", l, s.top(), input[i]);
                if (!s.empty() && s.top() != input[i++])
                    return false;
                if (!s.empty())
                    s.pop();
                // i++;
            }
    }

    if (!s.empty() && s.top() == input[i - 1])
        s.pop();

    return s.empty();
}

int main()
{
    scanf("%d\n", &n);
    scanf("%s\n", text);

    int count;
    scanf("%d\n", &count);

    while (count--)
    {
        scanf("%s\n", input);
        emptyStack();
        printf("%d\n", isPossible());
    }
}