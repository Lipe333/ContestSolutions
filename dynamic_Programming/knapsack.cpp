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
#define ii pair<int,int>
#define MAX 1e9

const ll INF = 10000000000LL;

ll dp[1000][1000];

vll vals(1000,-1);
vll peso(1000,-1);

ll pegados[1000][1000];

ll solve(int i, int k){
    if(i<0 || k == 0) return 0;

    if(dp[i][k]!=-1) return dp[i][k];

    ll pega = -INF, n_pega=-INF;

    n_pega = solve(i-1,k);

    if(peso[i] <= k)
        pega = solve(i-1,k-peso[i]) + vals[i];

    dp[i][k] = max(pega,n_pega);

    if(pega > n_pega) 
        pegados[i][k] = 1;
    else 
        pegados[i][k] = 0;

    return dp[i][k];

}


int main(){ _io
    // n itens e capacidade c
    ll n,c; cin >> n >> c;

    for(int i=0;i<n;i++)
        cin >> vals[i];

    for(int i=0;i<n;i++)
        cin >> peso[i];

    memset(dp,-1,sizeof(dp));

    ll ans = solve(n-1,c);


    cout << "Valor minimo de elementos que eu posso pegar: " << ans << endl;
    cout << "Elementos que eu peguei (Item, Peso) :\n";

    for(int i = n-1; i >= 0; i--) {
        if(pegados[i][c] == 1) {
            cout << i << " (valor: " << vals[i] << ", peso: " << peso[i] << ")\n";
            c -= peso[i];  // Atualiza a capacidade restante
        }
    }

}