#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int t, x;
vector<int> arr;

int main() {
    scanf("%d\n", &t);

    while (t--)
    {
        scanf("%d\n", &x);
        int many = ((int) log2l(x)) + 1;
        int size = 0;
        arr.clear();

        int i;
        for (i = 0; i < many; i++)
        {
            int k = x >> i;
            if (k & 1 && (x >> (i + 1)) & 1) {
                int j;
                arr.push_back(-1);
                for (j = i + 1; j < many; j++)
                {
                    int k2 = x >> j;
                    if (!(k2 & 1)) break;
                    arr.push_back(0);
                }

                i = j - 1;
                x += 1 << i;
            } else {
                    arr.push_back(k & 1);
            }
        }
        
        if ((x >> i) & 1) arr.push_back(1);

        printf("%d\n", arr.size());
        for (int i = 0; i < arr.size(); i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}