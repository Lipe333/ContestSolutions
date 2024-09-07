#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX (int)1e6

int pollens[MAX];

int soma_digitos(int flor) {
    int soma_digs = 0;
    while (flor > 0) {
        soma_digs += flor % 10;
        flor /= 10;
    }
    return soma_digs;
}

int main() {
    _io

    ll n, k;
    cin >> n >> k;
    vector<ll> flowers(n);
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
        pollens[flowers[i]]++;
    }

    for (int i = MAX; i >= 0 && k > 0; i--) {
        while (pollens[i] > 0 && k > 0) {
            int extract = soma_digitos(i);
            int ops = min(k, (ll)pollens[i]);
            
            pollens[i] -= ops;
            if (i - extract > 0) {
                pollens[i - extract] += ops;
            }
            k -= ops;

            if (k == 0) {
                cout << extract << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl; 
    return 0;
}
