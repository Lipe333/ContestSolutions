#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int, string> pis;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define MAX 1e9
#define all(x) x.begin(),x.end()

const int MOD = 998244353;

int n;
vi a;
vector<vector<vector<ll>>> dp;

ll solve(int i, int j, int last) {
    if (i == n) return 1; 

    ll &res = dp[i][j][last];
    if (res != -1) return res;

    res = 0;
    if (a[i] == j) {
        res = (res + solve(i+1, j, 0)) % MOD;
    }

    if (last == 0) {
        res = (res + solve(i+1, j+1, 1)) % MOD;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int &x : a) cin >> x;

        dp.assign(n, vector<vector<ll>>(n+1, vector<ll>(2, -1)));

        cout << solve(0, 0, 0) << "\n";
    }

    return 0;
}
