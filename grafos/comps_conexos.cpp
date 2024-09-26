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

vi adj[26];
vi vis(N,BRANCO);

int cont_conxs;

void dfs(int v){
    vis[v] = CINZA;
    for(auto& u : adj[v]){
        if (vis[u] == BRANCO)  dfs(u);
    }
    vis[v] = PRETO;
}

int main(){ _io

}