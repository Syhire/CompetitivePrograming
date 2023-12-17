#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int t;
    scanf("%d\n", &t);

    while (t--)
    {
        char str[60];
        scanf("%s", str);

        int len = strlen(str);

        int arr[60] = {false};

        for(int i = 0; i < len - 1; i++) {
            arr[i + 1] = str[i] == 'E' ? arr[i] : arr[i] + 1;
        }

        for(int i = len - 1; str[i] == 'E' && i > -1; i--) {
            arr[i] = arr[(i + 1) % len];
        }

        bool can = true;

        for(int i = 0; i < len && can; i++) {
            if (str[i] == 'E' && arr[i] != arr[(i + 1) % len]) can = false;
            if (str[i] == 'N' && arr[i] == arr[(i + 1) % len]) can = false;
        }

        printf("%s\n", can ? "YES" : "NO");

        // for(int i = 0; i < len; i++) printf("%d ", arr[i]);
        // printf("\n");
    }
}