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

struct Node{
    ll sum;
};

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

    /*
        Index i, valor V, nó X, intervalo lx até rx
    */
    void set(int i, ll v, int x, int lx, int rx){
        if(rx - lx == 1){
            sums[x] = v;
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
        // Setando um valor V na posição i que começa do nó 0 no intervalo de 0 até size
        set(i,v,0,0,size);
    }

    /*
        * Retorna a soma do intervalo [l,r] do nó x entre LX até RX
    */
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


int main(){ _io
    int n,m; cin >> n >> m;

    // cria e inicia a seg tree
    segtree st;
    st.init(n);

    vll vet(n);

    for(int i=0; i<n;i++) cin >> vet[i];
    
    // constroi a arvore de somas
    st.build(vet);


    while(m--){
        int op; cin >> op;

        if(op==1){
            //set element
            int i;
            ll v;
            cin>>i>>v;

            st.set(i,v);

        }else{
            // query a sum
            int l,r; cin >> l >> r;
            cout << st.sum_query(l,r) << "\n";
        }
    }   

    return 0; 

}