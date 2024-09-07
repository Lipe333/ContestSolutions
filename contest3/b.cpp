#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
typedef long long ll;
const ll INF = (ll) 1e+7;

using namespace std;

vi moedas;
vi pd;

int solve(int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (pd[x] != -1) return pd[x];
    int best = INF;

    for (int c : moedas) {
        best = min(best, solve(x-c) + 1);
    }

    pd[x] = best;
    return best;
}

signed main(){ _io
    int n, x; cin >> n >> x;
    
    moedas.resize(n);
    
    for (int i = 0; i < n; i++) cin >> moedas[i];
    
    pd.assign(x + 1, -1); 

    int result = solve(x);
    
    (result >= INF) ? cout << -1 << endl : cout << result << endl;
}
