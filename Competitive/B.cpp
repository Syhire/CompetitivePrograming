// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
 
// Function to find the total number
// of ways to tile a 2*N board using
// the given types of tile
 
long long int func(long long int idx, bool space, int n,
                   vector<vector<int> >& dp)
{
    if (idx > n + 1) {
        return 0;
    }
 
    if (idx == n + 1) {
        if (space == true) {
            return 0;
        }
        return 1;
    }
 
    if (dp[idx][space] != -1) {
        return dp[idx][space];
    }
 
    long long int cnt = 0;
    if (space == false) {
        cnt += func(idx + 1, false, n, dp);
        cnt += func(idx + 2, false, n, dp);
        cnt += 2 * func(idx + 2, true, n, dp);
    }
    else {
        cnt += func(idx + 1, false, n, dp);
        cnt += func(idx + 1, true, n, dp);
    }
    return dp[idx][space] = cnt % MOD;
}
 
int numTilings(int N)
{
    vector<vector<int> > dp(N + 2, vector<int>(3, -1));
    return func(1, false, N, dp);
}
 
// Driver Code
int main()
{
    int N;
    cin >> N;
    cout << numTilings(N);
 
    return 0;
}