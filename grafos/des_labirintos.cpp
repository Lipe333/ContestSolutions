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
#define all(x) x.begin(),x.end()
#define MAX 1e9

const int N = 100;

vi adj[N];

map<pair<int, int>, bool> deletada; 

vi caminho;

void acha_caminho_euleriano(int v) {
    for (int i = 0; i < adj[v].size(); i++) {
        int viz = adj[v][i];
        if (deletada[mp(v, viz)]) continue; 
        deletada[mp(v, viz)] = deletada[{viz, v}] = true;  
        acha_caminho_euleriano(viz);  
    }
    caminho.push_back(v);  
}

int main(){ _io
    int t; cin >> t;

    while(t--){

        int n,v,a; cin >> n >> v >> a;

        for(int i=0;i<N;i++)    adj[i].clear();
        deletada.clear();
        caminho.clear();

        for(int i=0;i<a;i++){
            int u,v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        acha_caminho_euleriano(n);

        cout << 2 * (caminho.size()-1) << endl;  

    }


}