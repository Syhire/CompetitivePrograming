#include <stdio.h>
#include <string.h>
using namespace std;

int input[10];
int num[10];
int taken[10];
int func[10]; // 0: +, 1: -, 2: *

bool possible;

int calcFunc(int a, int b, int func)
{
    switch (func)
    {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    }
}

int checkOut()
{
    int num1 = calcFunc(num[0], num[1], func[0]);
    int num2 = calcFunc(num1, num[2], func[1]);
    int num3 = calcFunc(num2, num[3], func[2]);
    int num4 = calcFunc(num3, num[4], func[3]);

    return num4;
}

void bsFunc(int len)
{
    if (possible)
        return;
    if (len == 4)
    {
        if (checkOut() == 23)
        {
            // printf("(((%d %c %d) %c %d) %c %d) %c %d = %d\n",
            //        num[0],
            //        func[0] == 1 ? '-' : func[0] == 2 ? '*'
            //                                          : '+',
            //        num[1],
            //        func[1] == 1 ? '-' : func[1] == 2 ? '*'
            //                                          : '+',
            //        num[2],
            //        func[2] == 1 ? '-' : func[2] == 2 ? '*'
            //                                          : '+',
            //        num[3],
            //        func[3] == 1 ? '-' : func[3] == 2 ? '*'
            //                                          : '+',
            //        num[4],
            //        checkOut());
            possible = true;
        }
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        func[len] = i;
        bsFunc(len + 1);
    }
}

void bsNumber(int len)
{
    if (possible)
        return;
    if (len == 5)
    {
        return bsFunc(0);
    }

    for (int i = 0; i < 5; i++)
    {
        if (!taken[i])
        {
            taken[i] = true;
            num[len] = input[i];
            bsNumber(len + 1);
            taken[i] = false;
        }
    }
}

bool chckInput() { return input[0] == 0 && input[1] == 0 && input[2] == 0 && input[3] == 0 && input[4] == 0; }

int main()
{
    while (scanf("%d %d %d %d %d\n", &input[0], &input[1], &input[2], &input[3], &input[4]) && !chckInput())
    {
        possible = false;
        bsNumber(0);
        printf("%s\n", possible ? "Possible" : "Impossible");
    }
}