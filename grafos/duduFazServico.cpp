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
#define MAX 1e9

const int N = 10005;

const int PRETO = -3;
const int CINZA = -2;
const int BRANCO = -1;

vi vis(N,BRANCO);
vi adj[N];

bool flag_cicle = false;

void dfs(int v) {
    //cout << "Visitando vertice " << v << endl;
    vis[v] = CINZA;
    for (auto u : adj[v]) {
        //cout << " --> vizinho " << u << endl;
        if (vis[u] == BRANCO)   dfs(u);

        if (vis[u] == CINZA)  flag_cicle = true;

        if (flag_cicle) return;
    }
    vis[v] = PRETO;
}

int main(){ _io
    int t; cin >> t;

    while(t--){
        
        int n,m; cin >> n >> m;
        
        
        for(int i=0;i<=n;i++){
            adj[i].clear();
            vis[i] = BRANCO;
        }

        for(int i=0;i<m;i++){
            int a,b; cin >> a >> b;
            adj[a].pb(b);
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == BRANCO) {
                dfs(i);
            }

            if (flag_cicle) {
                //cout << "  ------> ciclo encontrado\n";
                break;
            }
        }

    
        cout << (flag_cicle ? "SIM\n":"NAO\n");

        flag_cicle = false;

    }
}