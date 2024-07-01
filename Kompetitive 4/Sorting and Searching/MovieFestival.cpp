#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b;
vector<pair<int, int> > arr;

int main() {
    scanf("%d\n", &n);

    while (n--)
    {
        scanf("%d %d\n", &a, &b);
        // printf("%d %d\n", a, b);
        arr.push_back(make_pair(b, a));
    }

    sort(arr.begin(), arr.end());

    int curMov = 0, sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // printf("%d %d\n", arr[i].second, arr[i].first);
        if (curMov <= arr[i].second) {
            // printf("#\n");
            sum++;
            curMov = arr[i].first;
        }
    }

    printf("%d\n", sum);
}