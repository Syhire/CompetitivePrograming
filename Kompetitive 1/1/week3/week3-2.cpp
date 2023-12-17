#include <cstdio>

int main()
{
    int d, m;

    scanf("%d %d", &d, &m);
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;
    for (int i = 0; i < m - 1; i++)
    {
        total += month[i];
    }

    int day = (3 + d + total) % 7;

    switch (day)
    {
    case 1:
        printf("%s\n", "Monday");
        break;
    case 2:
        printf("%s\n", "Tuesday");
        break;
    case 3:
        printf("%s\n", "Wednesday");
        break;
    case 4:
        printf("%s\n", "Thursday");
        break;
    case 5:
        printf("%s\n", "Friday");
        break;
    case 6:
        printf("%s\n", "Saturday");
        break;
    default:
        printf("%s\n", "Sunday");
        break;
    }
}