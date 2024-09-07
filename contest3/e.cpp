#include<bits/stdc++.h>
#define _io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi  vector<int>
#define vll vector<ll>
#define MOD 1000000007
using namespace std;
typedef long long ll;

vector<vi> dp(1000010 + 1, vi(110 + 1));

bool ok(int x, int m){
    return x >= 1 && x <= m;
}

int main() { _io

    int n, m;
    cin >> n >> m;
    vi a(n);

    for(int i = 0; i < n; i++)  cin >> a[i];


    for(int i = 1; i <= m; i++){
        if(a[0] == i || a[0] == 0)
            dp[1][i] = 1;
    }
    
    for(int i = 2; i <= n; i++){
        for(int k = 1; k <= m; k++){

            if(a[i-1] != 0 && a[i-1] != k){
                dp[i][k] = 0;
                continue;
            }
            
            for(int prev = k - 1; prev <= k + 1; prev++){
                if(!ok(prev, m)){
                    continue;
                }
                dp[i][k] = (dp[i][k] + dp[i-1][prev]) % MOD;
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n][i]) % MOD;
    }
    
    cout << ans << endl;
}