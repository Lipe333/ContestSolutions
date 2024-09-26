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

const int N = 200010;
vector<ii> adj[N];

ll prim() {
    vector<bool> taken(N, false);
    priority_queue<ii, vector<ii>, greater<ii>> pq;  
    ll mst_cost = 0;  

    // Inserindo as arestas do nó inicial na fila de prioridade
    taken[0] = true;
    ii v;
    for (int j = 0; j < adj[0].size(); j++) {
        v = adj[0][j];
        pq.push({v.s,v.f});
    }

    while (!pq.empty()) {
        auto front = pq.top(); pq.pop();
        int u = front.s;  
        int w = front.f;  

        if (!taken[u]) {
            mst_cost += (ll)w;
            taken[u] = true;

            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j].f; 
                int w = adj[u][j].s;
                if (!taken[v]) {
                    pq.push({w, v});
                }
            }
        }
    }

    return mst_cost;
}

int main() {
    _io
    int m,n; 
    
    while(cin >> m >> n && m!=0 && n!=0){

        ll total_cost = 0;  // Custo total de todas as estradas

        for(int i=0;i<=n;i++){
            adj[i].clear();
        }

        for (int i = 0; i < n; i++) {
            int a, b, w; cin >> a >> b >> w;
            adj[a].pb({b, w});
            adj[b].pb({a, w});
            total_cost += w;  // Somando o custo total
        }

        ll mst_cost = prim();  // Calcula o custo da MST
        ll ans = total_cost - mst_cost;  // Calcula a economia
        cout << ans << endl;
    }

    return 0;
}
