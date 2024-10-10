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
#define all2(x) x.rbegin(),x.rend()

const int N = 1000;
const int BRANCO = -1;
const int CINZA = -2;
const int PRETO = -3;

vi adj[N];
vi vis(N, BRANCO);
vi numVertices;
vi parent(N), rank_set(N);

int cont;

// Função de inicialização do Union-Find
void init_union_find(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // Cada vértice inicialmente é seu próprio pai
        rank_set[i] = 0;    // rank_set inicial é 0
    }
}

// Função para encontrar o representante (raiz) do conjunto de 'v'
int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);  // Path compression
}

// Função para unir dois conjuntos
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        // União pelo rank_set (otimização)
        if (rank_set[root_u] < rank_set[root_v]) {
            parent[root_u] = root_v;
        } else if (rank_set[root_u] > rank_set[root_v]) {
            parent[root_v] = root_u;
        } else {
            parent[root_v] = root_u;
            rank_set[root_u]++;
        }
    }
}

void dfs(int v) {
    cont++;
    vis[v] = CINZA;
    for (auto& u : adj[v]) {
        if (vis[u] == BRANCO) dfs(u);
    }
    vis[v] = PRETO;
}

int main() {
    _io

    int n;
    cin >> n;

    init_union_find(n);

    bool inconsistente = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            if (ch == 'S' && i != j) {  
                adj[i].pb(j);
                adj[j].pb(i);
                unite(i, j);  
            } else if (ch == 'D' && i != j) {  
                if (find(i) == find(j)) {  
                    inconsistente = true;
                }
            }
        }
    }

    if (inconsistente) {
        cout << -1 << endl;
        return 0;  
    }

    int conexos = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] == BRANCO) {
            cont = 0;
            dfs(i);
            numVertices.pb(cont);
            conexos++;
        }
    }

    sort(all2(numVertices));  

    cout << conexos << endl;
    for (int i = 0; i < numVertices.size(); i++) {
        if (i != numVertices.size() - 1)
            cout << numVertices[i] << " ";
        else
            cout << numVertices[i];
    }
    cout << endl;

    return 0;
}
