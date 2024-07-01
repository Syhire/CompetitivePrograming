#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

char arr[20];
vector<char> chars;
int arrs[30];
char temp;

int main()
{
    int n;
    scanf("%d\n", &n);

    while (n--)
    {
        scanf("%s\n", arr);
        memset(arrs, -1, sizeof(int) * 30);
        chars.clear();
        for (int i = 0; i < strlen(arr); i++)
        {
            // printf("# %c(%d) = %d\n", arr[i], arr[i] - 'a', arrs[arr[i] - 'a']);
            if (arrs[arr[i] - 'a'] == -1)
                chars.push_back(arr[i]);
            arrs[arr[i] - 'a'] = i;
        }

        // printf("%d\n", chars.size());

        if (chars.size() == 1)
            printf("NO\n");
        else
        {
            printf("YES\n");
            temp = arr[arrs[chars[0] - 'a']];
            arr[arrs[chars[0] - 'a']] = arr[arrs[chars[1] - 'a']];
            arr[arrs[chars[1] - 'a']] = temp;
            printf("%s\n", arr);
        }
    }
}