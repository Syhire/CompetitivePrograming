#include <stdio.h>
#include <queue>
using namespace std;

queue<char> map[200010];

void clear( queue<char> &q )
{
   queue<char> empty;
   swap( q, empty );
}

int main() {
    int loop;
    scanf("%d\n", &loop);

    while (loop--)
    {
        for (int i = 0; i < 26; i++)
            clear(map[i]);

        for (int i = 0; i < 26; i++)
            map[0].push('a' + i);

        int n;
        scanf("%d\n", &n);

        int input;
        while (n--)
        {
            scanf("%d\n", &input);
            char temp = map[input].front();
            map[input].pop();
            map[input + 1].push(temp);
            printf("%c", temp);
        }
        printf("\n");
    }
}