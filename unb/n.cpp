#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;


int main(){ _io
    int n;
    ll x; cin >> n >> x;

    if(n==1) {
        cout << x << endl;
        return 0;
    }

    ll t1 = x, m2 = (3*2)%10, t2 = (x-m2);
     if (n == 2)  {
        cout << t2 << endl;
        return 0;
    }

    ll T_antepenultima = t1;
    ll T_penultima = t2;
    ll Ti = 0;
    for (int i = 3; i <= n; ++i) {
        int M_i = (3 * i) % 10;
        Ti = ((T_penultima + T_antepenultima) / 2) - M_i;

        T_antepenultima = T_penultima;
        T_penultima = Ti;
    }

    cout << Ti << endl;

}