#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define MAX 1e5+10
#define all(x) x.begin(),x.end()
#define MOD 998244353

const int N = MAX;

int t=1;
vi p(N), q(N);
vll pot(N);

void solve(){
    int n; cin >> n;

    vi res(n);

    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> q[i];

    int pos=0;
    int idxMaiorP=0, idxMaiorQ=0; //Maiores de P e Q no intervalo [0,i]
    for(int i=0;i<n;i++){

        if(p[i]>=p[idxMaiorP])
            idxMaiorP=i;

        if(q[i]>=q[idxMaiorQ])
            idxMaiorQ=i;
        
        if(p[idxMaiorP]>q[idxMaiorQ] || (p[idxMaiorP]==q[idxMaiorQ] && q[i-idxMaiorP]>p[i-idxMaiorQ]) ){
            res[i] = (pot[p[idxMaiorP]] + pot[q[i-idxMaiorP]])%MOD;
        }
        else{
            res[i] = (pot[q[idxMaiorQ]] + pot[p[i-idxMaiorQ]])%MOD;   
        }

    }

    for(int i=0;i<n;i++){
        cout << res[i] << (i==n-1?endl:" ");
    }

}


int main(){ _io
    cin >> t;

    pot[0]=1;
    pot[1]=2;
    for(int i=2;i<=pot.size();i++){
        pot[i] = (pot[i-1]*2)%MOD;
    }

    while(t--)
        solve();

    return 0;
}