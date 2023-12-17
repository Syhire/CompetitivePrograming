#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    int nilai[30] = {0};

    int sumTotal = 0;

    int minute, right = 0;
    char problem;
    char rightWrong[6];

    int i = 0;

    while (scanf("%d", &minute) && minute != -1)
    {

        scanf(" %c %s", &problem, rightWrong);

        i = problem - 'A';

        nilai[i]++;

        string rw = rightWrong;

        if (rw == "right")
        {
            sumTotal += minute + (nilai[i] - 1) * 20;
            right++;
        }
    }

    printf("%d %d", right, sumTotal);
}