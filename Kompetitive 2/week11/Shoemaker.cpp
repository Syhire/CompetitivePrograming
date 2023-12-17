#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    int loop;
    scanf("%dn", &loop);

    while (loop--)
    {
        int n;
        double time, fine;
        scanf("\n%d\n", &n);
        priority_queue<pair<double, int> > pq;

        for (int i = 0; i < n; i++)
        {
            scanf("%f %f\n", &time, &fine);
            pq.push(make_pair((fine / time), i));
        }

        while (!pq.empty())
        {
            printf("%d ", pq.top().second + 1);
            pq.pop();
        }
        printf("\n");
    }
}