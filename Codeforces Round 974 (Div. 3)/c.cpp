#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define all(a) a.begin(),a.end()
#define MAX 1e9


ll ouro_metade;
ll sum;
ll n;


bool f(ll x){
    //cout <<  ((ouro_metade*2*n) - sum) << endl;
    return ((ouro_metade*2*n) - sum) < x;
}

ll find_x(ll n){
    ll init=0,end=1e18;
    ll x,resp=1e18;

    // meu x tem que ser maior do que comp

    while (init<=end){
        x = (init+end)/2;
        
        if(f(x)){
            resp = min(resp,x);
            end = x-1;
        }else{
            init = x+1;
        }

    }
    return resp;
}


int main() {  _io

    int t;
    cin >> t;

    while (t--) {

        cin >> n;
        sum=0; ouro_metade=0;
        vll wealth(n);

        for (int i = 0; i < n; i++) {
            cin >> wealth[i];
            sum += wealth[i];
        }

        sort(all(wealth));

        if (n == 1 || n == 2) {

            cout << -1 << endl;
            continue;

        }
        
        ouro_metade = wealth[n/2];
        cout << find_x(n) << endl;

        // Solução matmática:
        // ll mid_gold = wealth[n/2];
        // cout << max(0LL, (mid_gold*2*n-sum+1)) << endl;

    }

    return 0;

}
