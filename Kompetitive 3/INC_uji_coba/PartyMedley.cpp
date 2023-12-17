#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
int students[210];

int main()
{
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d\n", &students[i]);

    int conf = 0;
    int maxRating = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int l = j + 1; l < n; l++)
            {
                int diff = max(students[i], max(students[j], students[l])) - min(students[i], min(students[j], students[l]));

                if (diff <= m)
                {
                    int sum = students[i] + students[j] + students[l];
                    conf++;
                    maxRating = max(maxRating, sum);
                }
            }
        }
    }

    if (conf > 0)
        printf("%d %d\n", conf, maxRating);
    else
        printf("%d\n", maxRating);
}