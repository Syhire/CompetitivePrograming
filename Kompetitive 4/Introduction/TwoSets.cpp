#include <stdio.h>
#include <vector>
using namespace std;

int n;

int main() {
    scanf("%d\n", &n);

    long long sum = n / 2.0 * (n + 1);

    if (sum % 2 == 1) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    bool arr[1000000];
    vector<int> nums;
    long long halfsum = sum / 2;

    int itr = n;

    for (itr = n; halfsum >= itr; itr--)
    {
        // printf("%d ", itr);
        nums.push_back(itr);
        halfsum -= itr;
        arr[itr] = true;
    }
    
    int size = nums.size();
    if (halfsum > 0) size++;

    printf("%d\n", size);

    for (int i = 0; i < nums.size(); i++)
    {
        printf("%d ", nums[i]);
    }
    
    if (halfsum > 0) printf("%d\n", halfsum);
    else printf("\n");

    arr[halfsum] = true;

    printf("%d\n", n - size);

    for (int i = n; i > 0; i--)
    {
        if (!arr[i]) printf("%d ", i);
    }
    
}