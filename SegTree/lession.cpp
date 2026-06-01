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

const int TAM = 100000;

int n,m;
ll vet[TAM], seg_tree[4*TAM];

void build(int no, int i, int j){
    if(i==j){
        seg_tree[no]=vet[i];
        return ;
    }

    int esq=no<<1, dir = esq+1, med=(i+j)>>1;

    build(esq,i,med);
    build(dir,med+1,j);
    seg_tree[no]=seg_tree[esq]+seg_tree[dir];
}

void update(int no, int i, int j, int pos, int v){

    if(i==j){
        seg_tree[no]=v;
        return ;
    }

    int esq=no<<1, dir = esq+1, med=(i+j)>>1;

    if(pos<=med)
        update(esq,i,med,pos,v);
    else 
        update(dir,med+1,j,pos,v);

    seg_tree[no]=seg_tree[esq]+seg_tree[dir];
}

ll query(int no, int i, int j,int a, int b){
    if(i>=a && j<=b)
        return seg_tree[no];

    if(i>b || j<a)
        return 0;

    int esq=no<<1, dir = esq+1, med=(i+j)>>1;

    return query(esq,i,med,a,b)+query(dir,med+1,j,a,b);
    
}

int main(){ _io
    cin >> n >> m;

    for(int i=0;i<n;i++) cin >> vet[i];

    build(1,0,n-1);

    // for(int i=0;i<n*4;i++) cout << seg_tree[i] << " ";
    // cout << endl;

    while(m--){
        int op, a, b;
        cin >> op >> a >> b;

        if(op==1){
            update(1,0,n-1,a,b);
        }
        else{
            cout << query(1,0,n-1,a,b-1) << endl;
        }

    }

    //cout << query(1,0,n-1,0,n-1) << endl;

}