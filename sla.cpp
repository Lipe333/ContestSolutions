#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define forn(i,n) for(int i=0;i<n;i++)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define vi vector<int>
#define vll vector<ll>
#define MAX 1e9
#define all(x) x.begin(),x.end()

const int maxn = 1e6+10;
const ll INF = 1e9+10; 
int n,m;
ll a[maxn];
ll l[maxn], r[maxn];

struct Node{
    ll cont;
};

Node segL[4*maxn], segR[4*maxn];

// Compressão de coordenadas
void compress(ll v[]){
    map<ll,ll> id;
    for(int i=0;i<n;i++) id[v[i]]=0;
    ll sz = 0;
    for(auto& [val, rank] : id) rank = sz++;
    for(int i=0;i<n;i++) v[i] = id[v[i]]; 
} 


Node merge(Node v1, Node v2){
    Node v;
    v.cont = v1.cont + v2.cont;
    return v;
}

void update(int v, int tl, int tr, int pos, Node new_val, Node seg[]){
    if(tl == tr)
        seg[v] = new_val;

    else{
        int tm = (tl+tr)/2;
        if(pos<=tm)
            update(v*2,tl,tm,pos,new_val,seg);
        else 
            update(v*2+1,tm+1,tr,pos,new_val,seg);
        seg[v] = merge(seg[v*2],seg[v*2+1]); 
    }
}

Node query(int v, int tl, int tr, int l, int r, Node seg[]){
    if(l>r) return {0};
    if(l==tl && r==tr) return seg[v];

    int tm = (tl+tr)/2;
    return merge(query(v*2,tl,tm,l,min(r,tm),seg),
                query(v*2+1,tm+1,tr,max(l,tm+1),r,seg));
}

int main(){ _io

    cin >> n;

    forn(i,n) cin >> a[i];
    compress(a); // como são valores unicos, posso aplicar a compressão 
    
    
    forn(i,n) {
        l[i] = query(1,0,n-1,a[i]+1,n-1,segL).cont;
        update(1,0,n-1,a[i],{1},segL);
    }


    for(int i=n-1;i>=0;i--){
        r[i] = query(1,0,n-1,0,a[i]-1,segR).cont;
        update(1,0,n-1,a[i],{1},segR);
    }

    ll ans=0;
    forn(i,n) ans += l[i]*r[i];

    cout << ans << endl;
    

    return 0;
}