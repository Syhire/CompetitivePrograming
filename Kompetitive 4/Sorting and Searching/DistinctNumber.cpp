#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

int main()
{
    scanf("%d\n", &n);
    int res = 1, input;

    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &input);
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1]) res++;
    }
    
    printf("%d\n", res);
}