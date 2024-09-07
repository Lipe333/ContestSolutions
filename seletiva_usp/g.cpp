#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vll vector<long long>
typedef long long ll;
using namespace std;

const int N = 1010;

ll dp[N][N];
vll places(N);
int n;

ll solve(int p, int t){
    //cout << "p: " << p << ", t: " << t << endl;
    if(p == n) return 0;
    if(dp[p][t]!=-1) return dp[p][t];
    dp[p][t] = min(solve(p+1,t)+abs(places[p]-places[p+1]),
                   solve(p+1,p)+abs(places[p+1]-places[t]));
    return dp[p][t];
}


int main() {_io
    cin >> n;
    places[0] = 0;
    for (int i = 1; i <= n; i++) cin >> places[i];
    memset(dp,-1,sizeof dp);
    cout << solve(0,0) << endl;

    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";        
    }
    cout << "\n";
}
