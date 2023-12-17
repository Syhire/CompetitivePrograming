#include <stdio.h>
#include <stack>
#include <deque>
#include <string>
#include <string.h>
using namespace std;

long long N, n;
deque<string> posfixFunction;

long long f(long long x);
long long stringToInt(string str, long long x);
string intToString(long long n);
long long calc(long long a, long long b, char op);
int floydCycleFinding(long long x);

int main()
{
    char input[105];
    while (true)
    {
        scanf("%lld %lld ", &N, &n);

        if (N == 0 && n == 0)
            break;

        while (scanf("%s", input))
        {
            posfixFunction.push_back(input);

            if (input[0] == '%')
                break;
        }

        printf("%d", floydCycleFinding(n));

        // long long test = f(n);
        // for (int i = 0; i < 10; i++)
        // {
        //     test = f(test);
        // }

        posfixFunction.clear();

        printf("\n");
    }
}

long long f(long long x)
{
    stack<string> tempPosfix;
    deque<string> tempPosfixFunc = posfixFunction;
    int numCount = 0;

    long long res = 0;

    while (!tempPosfixFunc.empty())
    {
        string tempStr = tempPosfixFunc.front();
        char tempString[105];
        strcpy(tempString, tempStr.c_str());

        // printf("DEBUG: %s \n", tempStr.c_str());

        if (tempString[0] != '*' && tempString[0] != '+' && tempString[0] != '%')
        {
            numCount++;
            tempPosfix.push(tempStr);
            tempPosfixFunc.pop_front();
        }
        else
        {
            tempPosfixFunc.pop_front();
            if (numCount >= 2)
            {
                // long long a = ((stringToInt(tempPosfix.top(), x) - 1) % N) + 1;
                long long a = stringToInt(tempPosfix.top(), x);
                tempPosfix.pop();

                // long long b = ((stringToInt(tempPosfix.top(), x) - 1) % N) + 1;
                long long b = stringToInt(tempPosfix.top(), x);
                tempPosfix.pop();

                // printf("DEBUG -> %lu %c %lu\n", b, tempString[0], a);

                res = calc(b, a, tempString[0]);
                // printf("DEBUG -> %lu\n", res);

                if (tempPosfixFunc.size() > 1)
                {
                    string temp = intToString(res);
                    tempPosfixFunc.push_front(temp);
                }

                while (!tempPosfix.empty())
                {
                    tempPosfixFunc.push_front(tempPosfix.top());
                    tempPosfix.pop();
                }
            }
            else
            {
                printf("ERROR");
                break;
            }
        }
    }

    // printf("FINAL : %d\n", res);
    return res;
}

string intToString(long long n)
{
    char temp[105];
    sprintf(temp, "%lld", n);
    string tempStr = temp;
    return tempStr;
}

long long stringToInt(string str, long long x)
{
    char temp[105];
    strcpy(temp, str.c_str());

    if (temp[0] == 'x')
        return x;
    else if (temp[0] == 'N')
        return N;
    else
    {
        long long a;
        sscanf(temp, "%lld", &a);
        return a;
    }
}

long long calc(long long a, long long b, char op)
{
    switch (op)
    {
    case '+':
        return a + b % N;
    case '*':
        return a * b % N;
    case '%':
        return a % b;
    default:
        return a;
        break;
    }
}

int floydCycleFinding(long long x)
{
    long long tortoise = f(x), hare = f(f(x));
    while (tortoise != hare)
    {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    int mu = 0;
    hare = x;

    while (tortoise != hare)
    {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }

    int lambda = 1;
    hare = f(tortoise);

    while (tortoise != hare)
    {
        hare = f(hare);
        lambda++;
    }

    // printf("%d\n", mu);
    return lambda;
}