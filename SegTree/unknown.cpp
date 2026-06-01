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

struct segtree {
    int size;
    vll sums;

    void init(int n){
        size = 1;
        while(size<n) size *= 2;
        sums.assign(2*size,0LL);
    }

    void build(vll& vet, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)vet.size()){
                sums[x] = vet[lx];  
            }
            return;
        }

        int mid = (lx+rx)/2;
        build(vet,2*x+1,lx,mid);
        build(vet,2*x+2,mid,rx);
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void build(vll& vet){
        build(vet,0,0,size);
    }

    void set(int i, ll v, int x, int lx, int rx){
        if(rx - lx == 1){
            sums[x] += v; //tive q mudar isso pra restrição da questão que adiciona ao q ja tem e n substitui
            return;
        }

        int mid = (lx+rx)/2;
        if(i<mid)
            set(i,v,2*x+1,lx,mid);

        else
            set(i,v,2*x+2,mid,rx);

        sums[x] = sums[2*x+1] + sums[2*x+2];
        
    }

    void set(int i, ll v){
        set(i,v,0,0,size);
    }

    ll sum_query(int l, int r, int x, int lx, int rx){
        if(lx >= r || rx <= l) return 0;

        if(lx >= l && rx <= r ) return sums[x];

        int mid = (lx+rx)/2;

        ll s1 = sum_query(l,r,2*x+1,lx,mid);
        ll s2 = sum_query(l,r,2*x+2,mid,rx);
       
        return s1+s2;
    }


    ll sum_query(int l, int r){
        return sum_query(l,r,0,0,size);
    }

};


int main(){
    ll n, q;
    cin >> n >> q;
    vll volumes(n);

    segtree st;
    st.init(n);

    for(int i=0; i<n;i++) cin >> volumes[i]; 

    
    st.build(volumes);

    while(q--){
        int op; 
        cin >> op;

        // cuidado com 0-based e 1-based
        if(op==1){
            int i; ll v;
            cin >> i >> v; i--;
            st.set(i,v);
        }else{
            int l,r; cin >> l >> r;
            cout << st.sum_query(l-1,r) << "\n";
        }
    }
    return 0;
}
