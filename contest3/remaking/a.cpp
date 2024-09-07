#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<long long>
typedef long long ll;
const ll MOD = (long long)(1e+9 + 7);
using namespace std;

int dp[10000010];

/*
    dp[0] = 1
    dp[1] = 1

*/

// Top-Down Solution
int req_solve(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];

    int ans=0;
    for(int d=1;d<=6;d++){
        ans+=req_solve(n-d);
    }

    dp[n] = ans;
    return dp[n];
}

// Bottom-Up solution
int solve(int n){
    dp[0] = 1;

    for(int i=1; i<=n;i++){

        for(int d=1;d<=6;d++){

            if(i-d>=0){
                dp[i] += dp[i-d]; 
            }

        }
    }

    return dp[n];
}

int main(){
    int n; cin >> n;
    //memset(dp,-1,sizeof(dp));
    cout << solve(n) << endl;
}