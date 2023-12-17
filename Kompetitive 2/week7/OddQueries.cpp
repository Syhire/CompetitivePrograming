#include <stdio.h>
#include <numeric>   
using namespace std;

int sizeArr;
bool arr[200010];

int main()
{
    int count, numTest, tempInput, l, r, k, odd;
    scanf("%d\n", &count);

    while (count--)
    {
        scanf("%d %d\n", &sizeArr, &numTest);
        odd = 0; 

        for (int i = 0; i < sizeArr; i++)
        {
            scanf("%d\n", &tempInput);
            arr[i] = tempInput & 1;
            if (arr[i]) odd++;
        }

        while (numTest--)
        {
            scanf("%d %d %d\n", &l, &r, &k);
            int sizeLR = r - l + 1;

            if (sizeLR == sizeArr) {
                printf("%s\n", (k & 1 ? sizeLR : 0) & 1 ? "YES" : "NO");
                continue;
            }

            bool sum = accumulate(arr + (l - 1), arr + r, 0) & 1;

            printf("%s\n", (odd - sum + (k & 1 ? sizeLR : 0)) & 1 ? "YES" : "NO");
        }
    }
}