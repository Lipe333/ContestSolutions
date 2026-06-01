#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

const int maxn = 2e5+10;
int t,n,m;
int pai[maxn], rnk[maxn];

struct Edge{
    int u,v,w;
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
};

vector<Edge> arestas;
vector<Edge> result;

void make_set(int v){
    pai[v] = v;
    rnk[v] = 0;
}

int find_set(int v){
    if(v == pai[v])
        return v;
    return pai[v] = find_set(pai[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(rnk[a] < rnk[b]) swap(a,b);
        pai[b] = a;

        if(rnk[a] == rnk[b])
            rnk[a]++;
    }
}
 
ll kruskal(){
    ll cost=0;

    forn(i,1,n) make_set(i);
 
    sort(all(arestas));


    for(auto a:arestas){
        if(find_set(a.u) != find_set(a.v)){
            cost += a.w;
            result.pb(a);
            union_sets(a.u,a.v);
        }

    }

    return cost;
}

int main(){ _io
    
    cin >> n >> m;
    forn(i,1,m){
        int u,v,w;
        cin >> u >> v >> w;
        arestas.pb({u,v,w});
    }

    cout << kruskal() << endl;

    return 0;
}