#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

long n, m, k, input;
vector<long> app;
vector<long> apr;

int main() {
    scanf("%ld %ld %ld\n", &n, &m, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%ld\n", &input);
        app.push_back(input);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%ld\n", &input);
        apr.push_back(input);
    }

    sort(app.begin(), app.end());
    sort(apr.begin(), apr.end());

    int idxApp = 0;
    int idxApr = 0;
    int res = 0;

    while (idxApp < app.size() && idxApr < apr.size())
    {
        int selisih = app[idxApp] - apr[idxApr];
        // printf("%d(%d), %d(%d): %d\n", idxApp, app[idxApp], idxApr, apr[idxApr], selisih);
        if (abs(selisih) <= k) {
            res++;  
            idxApp++;
            idxApr++;
            continue;
        }
        
        if (selisih > 0) idxApr++;
        else idxApp++;
    }
    
    printf("%d\n", res);

    // for (int i = 0; i < n; i++)
    //     printf("%ld ", app[i]);
    // printf("\n");

    // for (int i = 0; i < m; i++)
    //     printf("%ld ", apr[i]);
    // printf("\n");
}