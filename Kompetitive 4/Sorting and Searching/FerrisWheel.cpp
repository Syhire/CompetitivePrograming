#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int x, n, p;
vector<int> arr;

int main()
{
    scanf("%d %d\n", &n, &x);
    while (n--)
    {
        scanf("%d\n", &p);
        arr.push_back(p);
    }
    
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = arr.size() - 1;
    int res = 0;

    // for (int l = 0; l < arr.size(); l++)
    // {
    //     printf("%d ", arr[l]);
    // }
    // printf("\n");
    

    while (i <= j)
    {
        // printf("check: %d[%d] %d[%d]\n", arr[i],i, arr[j],j);
        int sum = arr[i] + arr[j];
        if (sum > x) {
            j--;
        } else {
            i++;
            j--;
        }
        res++;
    }

    printf("%d\n", res);
}