#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define _io ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define vi vector<int>
#define vll vector<ll>
#define MAX 1e9
#define all(x) x.begin(),x.end()

const int inf = 1e6;
const int maxn = 1e5+1;
int n,m;
vi g[maxn];
int dist[maxn], pai[maxn];

void bfs(int s){
    for(int i=0;i<=n;i++) {
        dist[i]=inf;
        pai[i]=-1;
    }

    queue<int> q;
    dist[s] = 0;
    pai[s] = -1;
    q.push(s);

    while(!q.empty()){
        auto u = q.front(); q.pop();

        for(auto v:g[u]){

            if(dist[v]>dist[u]+1){
                dist[v] = dist[u]+1;
                pai[v] = u;
                q.push(v);
            }

        }

    }


}


int main(){ _io

    cin >> n >> m;

    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    bfs(1);

    if(dist[n]==inf){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    //cout << dist[n]+1 << endl;

    vi path;
    int curr = n;
    while(curr!=-1){
        path.pb(curr);
        if(curr == 1) break;
        curr = pai[curr];
    }

    reverse(all(path));

    cout << path.size() << endl;
    for(auto x:path) cout << x << " ";
    cout << endl;

    return 0;
}