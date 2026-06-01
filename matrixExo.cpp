#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define _io ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define forn(i, a, b) for(int i = a; i <= (int)b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(),x.end()

const int MAXK = 11, MOD=1e6;

ll t,n,k,l;

struct Matrix {
    vector<vector<ll>> m;
    Matrix(int x, int y) : m(x, vector<ll>(y, 0)) {}
};

Matrix mult(Matrix a, Matrix b){
    int dimx = a.m.size();
    int dimy = b.m[0].size();
    int dimz = a.m[0].size();
    Matrix c(dimx,dimy);

    for(int i=0;i<dimx;i++){
        for(int j=0;j<dimy;j++){
            for(int x = 0; x < dimz; x++){ 
                c.m[i][j] = (c.m[i][j]+a.m[i][x]*b.m[x][j])%MOD;
            }
        }
    }
    
    return c;
}

Matrix I(){
    Matrix res(2, 2);
    for(int i=0;i<2;i++) res.m[i][i] = 1;
    return res;
}

Matrix fmexp(Matrix base, ll exp){
    Matrix resp = I();
    while(exp>0){
        if(exp&1) resp = mult(resp,base);
        base = mult(base,base);
        exp >>= 1;
    }
    return resp;
}

void solve(){
    cin >> n >> k >> l;

    k%=MOD; l%=MOD;

    Matrix T(2,2);
    T.m[0][0] = k;
    T.m[0][1] = l;
    T.m[1][0] = 1;
    T.m[1][1] = 0;

    Matrix f1(2,1);
    f1.m[0][0] = k;
    f1.m[1][0] = 1;
        
    Matrix ans = mult(fmexp(T,n/5-1),f1);
    string resp = to_string(ans.m[0][0]);
    string comp(max(0, 6 - (int)resp.size()), '0');

    cout << comp+resp << endl;

}

int main(){ _io
    t=1;
    while(t--)
        solve();
    return 0;
}