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


ll find_ans(ll init, ll end, vll& v, vll& prefix) {
    ll resp = LLONG_MAX;

    while (init <= end) {
        ll i = (init + end) / 2;
        ll pos = prefix[i];
        ll neg = prefix[end] - prefix[i];
        ll dif = abs(pos - neg);

        if (dif < resp) {
            resp = dif;
            end = i - 1;
        } else {
            init = i + 1;
        }
    }

    return resp;
}

int main() {
    _io
    int t; cin >> t;

    while (t--) {
        ll n, k; cin >> n >> k;

        vll v(n,0),prefix(n,0);

        for (int i = 0; i < n; i++) {
            v[i] = k + i;
        }

        prefix[0] = v[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + v[i];
        }


        ll ans = find_ans(0, n - k, v, prefix);
        cout << "HERE\n";
        cout << ans << endl;
    }
}
