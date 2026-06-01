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
#define MAX 1e9
#define all(x) x.begin(),x.end()

const int N_MAX = 1010;
const int INF = 1e8;

ll h[N_MAX];
ll s[N_MAX];

ll n,x;


int main(){ _io

    cin >> n >> x;

    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<ll> dp(x + 1, 0);

    for(int i = 0; i < n; i++) {
        for(int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }

    cout << dp[x] << endl;

    return 0;
}