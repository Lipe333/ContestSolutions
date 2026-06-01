#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define M_MAX 110
#define all(x) x.begin(), x.end()

const ll INF = 100000000000000;

vi o(M_MAX, -1);
vi l(M_MAX, -1);

ll dp[110][10010];

int n, m;

ll solve(int i, int faltam){

    if (faltam == 0) return 0; 

    if (i < 0 || faltam <0) return INF;

    if (dp[i][faltam] != -1)  return dp[i][faltam];
    

    dp[i][faltam] = INF;

    for (int x = 0; x <= l[i]; x++){

        if (faltam - x * o[i] >= 0)
            dp[i][faltam] = min(dp[i][faltam], solve(i - 1, faltam - (x * o[i])) + x);
            
    }

    return dp[i][faltam];
}

int main(){ _io

    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> o[i];

    for (int i = 0; i < m; i++)
        cin >> l[i];

    memset(dp, -1, sizeof(dp));

    ll ans = solve(m - 1, n);
    if (ans >= INF) cout << -1 << endl; 
    else cout << ans << endl;

    cout << sizeof(INF);
    return 0;

}



/*
    Lições do dia:
        1. Prestar atenção para sempre considerar o indice 0 no caso base (i<0!!!!!)
        2. O valor somado/subtraido deve estar dentro da função min junto a chamada da função SOLVE (min(v,solve+x))
        3. Prestar atenção nas dimensões da DP (dp[m][n] para dp[n][m])
        4. Tomar cuidado com o infinito considerado pois pode dar OVERFLOW
*/