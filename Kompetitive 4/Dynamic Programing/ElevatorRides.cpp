#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int n, x, fin;
int memo[1050000];
int arr[25];
int minMoves = -1;

string DecimalToBinary(int num)
{
    string str;
      while(num){
      if(num & 1) // 1
        str+='1';
      else // 0
        str+='0';
      num>>=1; // Right Shift by 1  
    }    
      return str;
}

int checkSolution(int visited, int num) {
  if (num == n) {
    solve();
  }
}

int solve(int state, int moves, int leftOver) {
    if (state == fin) return moves;
    if (memo[state] != -1) return memo[state];

    int res = checkSolution(state, 0);

    return memo[state] = res;
}

int main() {
    scanf("%d %d\n", &n, &x);
    fin = (1 << n) - 1;

    for (int i = 0; i < n; i++)
        scanf("%d\n", &arr[i]);
    
    memset(memo, -1, sizeof(int) * 1050000);

    printf("%d: %s\n",fin, DecimalToBinary(fin).c_str());
    printf("%d\n", solve(0, 0, n));
}