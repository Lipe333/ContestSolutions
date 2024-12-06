#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define MAX 1e9
#define all(x) x.begin(),x.end()

vi dp(200,-1);

int bolanacci(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    if(dp[n]!=-1) return dp[n];

    dp[n] = bolanacci(n-1) + bolanacci(n-2) - bolanacci(n-3);
    return dp[n];
}

int main(){ _io
    int n; cin >> n;

    cout << bolanacci(n) << endl;
}