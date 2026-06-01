#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define endl '\n'
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()

const int maxn = 2e5+5;
int n,m;
int pai[maxn];
bool vis[maxn];
vi g[maxn];

int beg=-1,fin=-1;

bool dfs(int u, int parent){

    pai[u] = parent;    
    vis[u]=true;

    for(auto v:g[u]){       
        if(v==parent)
            continue;

        //ciclo detectado
        if(vis[v] && v!=parent){
            beg= u;
            fin = v;
            return true;
        }

        if(!vis[v]){
            if(dfs(v,u)) return true;
        }  
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    bool cicle=false;
    for(int i=1;i<=n;i++){
        if(!vis[i])
            if(dfs(i,0)) {
                cicle=true;
                break;
            }
    }

    if(!cicle){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vi resp;
    int v=beg;
    resp.pb(fin);
    while(v!=fin){
        resp.pb(v);
        v = pai[v];
    }
    resp.pb(fin);

    cout << resp.size() << endl;
    for(auto& x:resp)
        cout << x << " ";

    cout << endl;
    
    return 0;
    
 
}