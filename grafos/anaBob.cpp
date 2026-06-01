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
#define MAX 2*100000
#define all(x) x.begin(),x.end()

const int INF = INT_MAX;

// const int BRANCO = -1;
// const int CINZA = -2;
// const int PRETO = -3;
// const int POSBOB = -4;

vi adj[MAX];
//vi vis(MAX,BRANCO);
int distAna[MAX], distBob[MAX];
int n,x;

/*
 * DFS -> CALCULA A DISTANCIA PRA UM GRAFO ACICLICO
 * BFS -> CALCULA A DISTANCIA PRA UM GRAFO CICLICO
 */

void dfs(int v, int pai, int dist[], int cont) {
    dist[v] = cont;

    for(auto u : adj[v]){
        if(u != pai){
            dfs(u,v, dist, cont+1);
        }
    }

}

int main(){ _io
    cin >> n >> x;

    for(int i=0;i<n;i++){
        int u,v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);

    }

    dfs(x,0,distBob,0);
    dfs(1,0,distAna,0);

    int ans=0;
    for(int i=1;i<=n;i++){
        if(distAna[i]>distBob[i]) ans = max(ans,distAna[i]);
    }

    cout << ans*2 << endl;


}