#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<double,int> &a, const pair<double,int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    int loop;
    scanf("%dn", &loop);

    while (loop--)
    {
        int n;
        int time, fine;
        scanf("\n%d\n", &n);
        vector<pair<double, int> > arr;

        arr.clear();

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d\n", &time, &fine);
            arr.push_back(make_pair((fine * 1.0 / time), i + 1));
        }

        sort(arr.begin(), arr.end(), compare);
        int size =  arr.size();

        for (int i = 0; i < size; i++)
            if (i == 0) printf("%d", arr[i].second, arr[i].first);
            else printf(" %d", arr[i].second, arr[i].first);
            
        printf("\n");
        if (loop) printf("\n");
    }
}