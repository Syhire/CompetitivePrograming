#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

char str[10];
int n;
unordered_set<string> s;
vector<string> v;

char rep[10] = { '\0' };
bool used[10] = { false };

void solve(int num) {
    if (num == n) {
        string temp = rep;
        // printf("%s\n", temp.c_str());
        s.insert(temp);
    } else {

        for (int i = 0; i < n; i++)
        {
            if (used[i]) continue;
            rep[num] = str[i];
            used[i] = true;
            solve(num + 1);
            used[i] = false;
            rep[num] = '\0';
        }
    }
}

int main() {
    scanf("%s\n", str);
    n = strlen(str);

    solve(0);

    printf("%d\n", s.size());
    v.insert(v.end(), s.begin(), s.end());
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++)
        printf("%s\n", v[i].c_str());
}