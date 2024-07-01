#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b;
vector<pair<int, bool> > arr;

int main() {
    scanf("%d\n", &n);

    while (n--)
    {
        scanf("%d %d\n", &a, &b);
        arr.push_back(make_pair(a, true));
        arr.push_back(make_pair(b, false));
    }

    sort(arr.begin(), arr.end());

    int sum = 0, maxSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].second) {
            sum++;
            maxSum = max(maxSum, sum);
        } else {
            sum--;
        }
    }

    printf("%d\n", maxSum);
}