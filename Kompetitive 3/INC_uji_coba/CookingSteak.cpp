#include <stdio.h>

using namespace std;

int n;
int timeCook[100010];
int steaks[100010];
int orders[100010];

int main()
{
    scanf("%d\n", &n);

    for (int i = 0; i < n - 1; i++)
        scanf("%d\n", &timeCook[i]);

    for (int i = 0; i < n; i++)
        scanf("%d\n", &steaks[i]);

    for (int i = 0; i < n; i++)
        scanf("%d\n", &orders[i]);

    unsigned long long time = 0;
    bool isPossible = 1; // TRUE

    // algo
    for (int i = n - 1; i >= 0; i--)
    {
        // printf("#%d o:%d, s:%d\n", i, orders[i], steaks[i]);

        int need = orders[i] - steaks[i];
        if (need <= 0)
            continue;

        unsigned long long cookTime = 0;

        for (int j = i - 1; j >= 0; j--)
        {
            cookTime += timeCook[j];

            if (steaks[j] <= 0)
                continue;

            // printf("-%d %ds, %d, %d\n", j, cookTime, need, steaks[j]);

            if (need > steaks[j])
            { // need > steaks
                time += steaks[j] * cookTime;
                need -= steaks[j];
                steaks[j] = 0;
            }
            else
            { // need <= steaks
                time += need * cookTime;
                steaks[j] -= need;
                need = 0;
                break;
            }
        }

        // printf("-> %d\n", need);

        if (need > 0)
        {
            isPossible = 0;
            break;
        }
    }

    if (isPossible)
        printf("%llu", time);
    else
        printf("%d", -1);
}
