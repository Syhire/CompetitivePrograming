#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vA;
vector<int> vB;

int main()
{
    int t, n, k, q;
    scanf("%d\n", &t);

    while (t--)
    {
        scanf("%d %d %d\n", &n, &k, &q);

        int input;
        vA.clear();
        vB.clear();

        for (int i = 0; i < k; i++)
        {
            scanf("%d\n", &input);
            vA.push_back(input);
        }

        for (int i = 0; i < k; i++)
        {
            scanf("%d\n", &input);
            vB.push_back(input);
        }

        for (int i = 0; i < q; i++)
        {
            scanf("%d\n", &input);
            int lower = lower_bound(vA.begin(), vA.end(), input) - vA.begin();
            int upper = upper_bound(vA.begin(), vA.end(), input) - vA.begin();

            // kalau udah ada di situnya
            if (vA[lower] == input)
            {
                printf("%d ", vB[lower]);
                continue;
            }

            lower--;
            double timeStart = 0, timeEnd = vB[upper];
            if (lower > -1)
                timeStart = vB[lower];

            double speed = (vA[upper] - (lower > -1 ? vA[lower] : 0)) / (timeEnd - timeStart);

            // printf("%d(%.3lf) -> %d [%.3lf] -> %d(%.3lf)\n", lower, timeStart, input, speed, upper, timeEnd);
            printf("%d ", (int)(timeStart + (input - (lower > -1 ? vA[lower] : 0)) / speed));
        }

        printf("\n");
    }
}