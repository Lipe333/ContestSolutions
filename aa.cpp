#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

#define _io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define forn(i, a, b) for(int i = a; i <= (int)b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(),x.end()

const ll MOD=1e9+7;
const int maxn = 2e5+10;
vector<ii> g[maxn];
int n,q;
ll qtd[maxn];
ll sub[maxn];
ll cost = 0;

void dfs(int u, int pai){

    sub[u]=1;

    for(auto [v,w]:g[u]){
        if(v==pai) 
            continue;
        dfs(v,u);
        cost += 1LL * w * sub[v] * (n-sub[v]);
        sub[u] += sub[v];
    }

}


int main(){ _io
    cin >> n >> q;
    vector<pair<int,ii>> ord;
    for(int i=0; i<n-1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].pb(mp(v,w));
        g[v].pb(mp(u,w));
        ord.pb(mp(u,mp(v,w)));
    }

    dfs(1,0);
/*     cout << cost << endl;
    for(int i=1;i<=n;i++)
        cout << sub[i] << " ";
    cout << endl; */
    for(int j=0; j<(int)ord.size(); j++){
        int u = ord[j].fi;
        int v = ord[j].sc.fi;
        ll s = (sub[u] < sub[v]) ? sub[u] : sub[v];
        qtd[j+1] = s * (n - s);
    }

    ll costMod = 0;
    for(int j=1; j<=(int)ord.size(); j++){
        ll w = ord[j-1].sc.sc;
        costMod = (costMod + (w % MOD) * (qtd[j] % MOD)) % MOD;
    }

    while(q--){
        int j,x;
        cin >> j >> x;
        ll oldW = ord[j-1].sc.sc;
        ll c = qtd[j] % MOD;
        costMod = (costMod - (oldW % MOD) * c % MOD + MOD) % MOD;
        costMod = (costMod + (ll)x % MOD * c) % MOD;
        ord[j-1].sc.sc = x;
        cout << costMod << endl;
    }

    return 0;
}
