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

const int maxn = 1e5+10;
const ll INF = 1e9+10; 
int n,m;
ll a[maxn];

// Seg para computar o minimo e a quantidade
// de vezes que ele aparece em um range
struct Value{
    ll mn;
    int cont;
};

Value seg[4*maxn];

Value merge(Value v1, Value v2){
    Value v;
    v.mn = min(v1.mn,v2.mn);
    v.cont = ( v1.mn == v2.mn ? v1.cont+v2.cont : (v1.mn<v2.mn ? v1.cont : v2.cont));
    return v;
}

void build(ll a[], int v, int tl, int tr){
    if(tl==tr){
        seg[v] = {a[tl],1};
    }else{
        int tm = (tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        seg[v] = merge(seg[v*2], seg[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, ll new_val){
    if(tl == tr)
        seg[v] = {new_val,1};

    else{
        int tm = (tl+tr)/2;
        if(pos<=tm)
            update(v*2,tl,tm,pos,new_val);
        else 
            update(v*2+1,tm+1,tr,pos,new_val);
        seg[v] = merge(seg[v*2],seg[v*2+1]); 
    }
}

Value query(int v, int tl, int tr, int l, int r){
    if(l>r) return {INF,1};
    if(l==tl && r==tr) return seg[v];

    int tm = (tl+tr)/2;
    Value s = merge(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(l,tm+1),r));
    return s;
}


int main(){ _io

    cin >> n >> m;
    forn(i,n) cin >> a[i];

    // Inicializa com INF para computar o mínimo
    forn(i,(n+1)*4) seg[i] = {INF,1};
    build(a,1,0,n-1);

    // for(int v=1;v<=n*4;v++)
    //     cout << seg[v] << " ";
    // cout << endl;

    while(m--){

        int op;
        cin >> op;

        if(op==1){
            int i;
            ll v;
            cin >> i >> v;
            update(1,0,n-1,i,v); // chamar a partir do idx 1, de 0 a n-1 se for 0-indexed

        }else{
            int l,r;
            cin >> l >> r;
            //l--;r--;
            Value v = query(1,0,n-1,l,r-1);
            cout << v.mn << " " << v.cont << endl; // a questao pede do intervalo l a r-1
        }

    }

    return 0;
}