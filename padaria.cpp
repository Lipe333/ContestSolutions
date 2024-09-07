#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
                tree_order_statistics_node_update> indexed_set;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>

int main(){ _io
    ll n,p;
    cin >> n >> p;

    vll fila(n);
    for(int i=0;i<n;i++) cin >> fila[i];

    vll p_possiveis(n);
    for(int i=0;i<n;i++) p_possiveis[i] = (fila[i]/p);

    indexed_set s;
    for(int i=0; i<n;i++){
        s.insert({p_possiveis[i],i});
        auto x = s.order_of_key({p_possiveis[i],i});

        //cout << i << " " << x << " " << p_possiveis[i] << endl;
        cout << i-(x) << " ";
    }
    cout << endl;

}