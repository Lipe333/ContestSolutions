#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll solve(ll N, ll X, vector<ll>& coins){

    ll dp[X + 1] = {};
    dp[0] = 1;

    for (int i = 1; i <= X; i++) {
        for (int j = 0; j < N; j++) {
            if (coins[j] > i)
                continue;
            dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
        }
    }
    return dp[X];
}

int main(){
    _io;
    int n, x;
    cin >> n >> x;
    vector<ll> moedas(n);
    for (int i = 0; i < n; i++) {
        cin >> moedas[i];
    }

    cout << solve(n,x,moedas) << endl;
}
