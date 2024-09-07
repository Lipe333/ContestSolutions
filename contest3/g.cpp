#include<bits/stdc++.h>
#define _io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi  vector<int>
#define vll vector<ll>
using namespace std;
typedef long long ll;


ll solve(ll n, ll x, vector<ll> preco, vector<ll> pages){

    vll dp(x+1,0);

    for (int i = 0; i < n; i++) {
        for (int C = x; C > 0; C--) {
            if (preco[i] <= C)
                dp[C] = max(dp[C], pages[i] + dp[C - preco[i]]);
        }
    }
    return dp[x];
}

int main(){ _io

    ll n,x; cin >> n >> x;

    vll preco(n);
    vll pages(n);

    for(int i=0;i<n;i++) cin >> preco[i];
    for(int i=0;i<n;i++) cin >> pages[i];

    cout << solve(n, x, preco, pages) << endl;
}
