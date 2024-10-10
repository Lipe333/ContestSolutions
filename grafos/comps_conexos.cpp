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

const int N = 26;
const int PRETO = -3;
const int CINZA = -2;
const int BRANCO = -1;

vi adj[N];
vi vis(N,BRANCO);
vector<vector<char>> componentes;

void dfs(int v,vector<char>& componente){
    vis[v] = CINZA;
    componente.pb(v+'a');
    for(auto& u : adj[v]){
        if (vis[u] == BRANCO)  dfs(u,componente);
    }
    vis[v] = PRETO;
}

int main(){ _io
    int n; cin >> n;

    int caso=1;
    while(n--){
        int v,e; cin >> v >> e;

        for(int i=0;i<N;i++){
            adj[i].clear();
            vis[i] = BRANCO;
        }

        for(int i=0; i<e; i++){
            char v1, v2; cin >> v1 >> v2;
            adj[v1 -'a'].pb(v2-'a');
            adj[v2 -'a'].pb(v1-'a');
        }

        componentes.clear();

        for(int i = 0; i < v; i++){
            if (vis[i] == BRANCO) {
                vector<char> componente;
                dfs(i, componente);
                sort(componente.begin(), componente.end()); 
                componentes.pb(componente);
            }
        }

        // Imprimir resultados
        cout << "Case #" << caso++ << ":\n";
        for (auto& componente : componentes) {
            for (char c : componente) cout << c << ",";
            cout << "\n";
        }
        cout << componentes.size() << " connected components\n";

        // Sempre imprimir linha em branco após cada caso
        cout << "\n";

    }

    return 0;
}