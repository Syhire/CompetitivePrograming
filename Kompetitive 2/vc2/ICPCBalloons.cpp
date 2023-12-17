#include <stdio.h>
#include <set>
using namespace std;

int main() {
    int t;
    scanf("%d\n", &t);

    while (t--)
    {
        int n;
        char str;
        set<char> solved;
        
        int balloon = 0;

        scanf("%d\n", &n);

        // printf("%d: \n", n);

        for (int i = 0; i < n; i++)
        {
            scanf("%c\n", &str);

            // printf("%c: %d\n", str, (solved.find(str) == solved.end()));

            if(solved.find(str) == solved.end()) balloon+= 2;
            else balloon++;

            solved.insert(str);
        }
        
        printf("%d\n", balloon);
    }
}