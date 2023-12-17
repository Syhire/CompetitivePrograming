#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int count, countIdx;

    scanf("%d", &count);

    int w, h;

    scanf("%d %d", &w, &h);

    int max = (int)sqrt((w * w) + (h * h));
    int input = 0;

    for (countIdx = 0; countIdx < count; countIdx++)
    {
        scanf("%d", &input);

        if (input > max)
            printf("NE\n");
        else
            printf("DA\n");
    }

    return 0;
}