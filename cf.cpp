#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define forn(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(),x.end()

const int maxn = 3e5+10;
int n;
int d[maxn];
ld p[maxn], dp[maxn];

ld solve(int i){
    //if(i > n) return 1;
    if(dp[i]!=-1) return dp[i];

    int nxt = (i==n ? 1 : i+1);
    
    ld continuar = 1 + solve(nxt);
    ld estacionar = d[i];
    
    dp[i] = p[i] * min(estacionar, continuar) + (1 - p[i]) * continuar;
    
    return dp[i];
}


int main(){ _io

    cin >> n;
    forn(i,1,n) cin >> d[i];
    forn(i,1,n) cin >> p[i];

    fill(dp, dp + maxn, -1.0L);
    cout << fixed << setprecision(6) << solve(1) << endl;

    return 0;
}