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
#define MAX 110
#define all(x) x.begin(),x.end()

const double INF = 1e9;
const int N = 110;
const int C = 2010;
const int G = 20;


// itens, min calorias, max gordura
double dp[N][C][G];

vi caloria(N);
vi gordura(N);
vector<double> preco(N);

double solve(int i, int j, int k){
    if(j<=0 && k>=0) return 0.0;
    
    if(i<0) {
        if(j<=0 && k>=0) return 0.0;
        return INF;
    }

    if(dp[i][j][k] != -1.0) return dp[i][j][k];

    dp[i][j][k] = solve(i-1,j,k);

    if(k - gordura[i] >= 0){
        dp[i][j][k] = min(dp[i][j][k],solve(i-1,max(0,j-caloria[i]), k-gordura[i])+preco[i]);
    }

    return dp[i][j][k];
}


int main(){ _io
    int n,c,g; cin >> n >> c >> g;

    for(int i=0; i<n;i++){
        cin >> caloria[i];
        cin >> gordura[i];
        cin >> preco[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            for (int k = 0; k <= g; k++) {
                dp[i][j][k] = -1.0;
            }
        }
    }
    
    double ans = solve(n-1,c,g);

    if(ans>=INF) cout << -1 << endl;
    else cout << fixed << setprecision(2) << ans << endl;

    return 0;

}