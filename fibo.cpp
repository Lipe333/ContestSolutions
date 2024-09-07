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

ll dp[1000010];

ll fibo(int n){

    if(n<=2) return 1;

    if(dp[n]!=-1) return dp[n];

    dp[n] = fibo(n-1)+fibo(n-2);

    return dp[n];
}

int main(){ _io

    int n; cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << fibo(n) << endl;

}