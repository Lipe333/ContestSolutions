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

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() { _io
    int t;
    cin >> t;

    while (t--) {
        ll x, y, k; 
        cin >> x >> y >> k;
        
        ll x_moves = ceil_div(x, k);
        ll y_moves = ceil_div(y, k);
        
        cout << max(2 * x_moves - 1, 2 * y_moves) << "\n";
    }

}