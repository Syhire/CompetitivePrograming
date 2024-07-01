#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, a;
vector<pair<int, int> > arr;

int main() {
    scanf("%d %d\n", &n, &x);

    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &a);
        arr.push_back(make_pair(a, i + 1));
    }

    sort(arr.begin(), arr.end());
    
    int i= 0, j = arr.size() - 1;
    for (; i < j;)
    {
        int sum = arr[i].first + arr[j].first;
        if (sum > x) {
            j--;
        } else if (sum < x) {
            i++;
        } else {
            printf("%d %d\n", arr[i].second, arr[j].second);
            break;
        }
    }

    if (i >= j) {
        printf("IMPOSSIBLE\n");
    }
}