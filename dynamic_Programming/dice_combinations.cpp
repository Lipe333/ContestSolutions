#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define MAX (int)1e6

int dp[10000000];

int dice[6] = {1,2,3,4,5,6};

ll solve(int n){
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        for(int d:dice){
            if(i-d >= 0){
                dp[i] += dp[i-d];
                cout << "dp[" << i << "]=" << dp[i] << endl;
                dp[i] %= (1000000000+7);
            }
        }
    }

    return dp[n];
}

ll req_solve(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    
    int res;
    for(auto& d:dice){
        dp[n] += req_solve(d); 
    }

    return res;
}

int main(){ _io
    int n; cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << req_solve(n) << endl;
}