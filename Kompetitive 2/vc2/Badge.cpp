#include <stdio.h>
using namespace std;

int n;    
int arr[1010];

int findDouble(int x) {
    bool isVisited[1010] = {false};

    while(!isVisited[x]) {
        isVisited[x] = true;
        x = arr[x];       
    }
    
    return x;
} 

int main() {
    scanf("%d\n", &n);
    for(int i = 1; i <= n; i++) scanf("%d\n", &arr[i]);
    for(int i = 1; i <= n; i++) printf("%d ", findDouble(i));
}