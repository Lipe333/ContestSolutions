#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
using namespace std;
typedef long long ll;

vector<vector<ll>> dp(1000, vector<ll>(1000));

ll solve(vector<string>& grid, ll N){
    

    for (int i = 0; i < N; i++) {
        if (grid[i][0] == '*')
            break;
        dp[i][0] = 1;
    }

    for (int j = 0; j < N; j++) {
        if (grid[0][j] == '*')
            break;
        dp[0][j] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (grid[i][j] != '*')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    
    return dp[N - 1][N -1];
}

int main()
{ _io
    int n; cin >> n;

    vector<string> grid(n);
    for(int i=0; i<n; i++){
        cin >> grid[i];
    }
  
    cout << solve(grid, n) << "\n";
}
