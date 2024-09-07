#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<long long>
typedef long long ll;
const ll MOD = (long long)(1e+9 + 7);
using namespace std;

vi dp(10000000);

int dado[6] = {1,2,3,4,5,6};

void solve(int n){
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        for(int c : dado){
            if(i-c >= 0){ 
                dp[i] += dp[i-c];
                dp[i] %= MOD;
            }
        }
    }
}


int main(){ 
    _io
    int n; 
    cin >> n;
    solve(n);
    cout << dp[n] << endl;
}