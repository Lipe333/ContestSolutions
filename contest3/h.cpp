#include<bits/stdc++.h>
#define _io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi  vector<int>
#define vll vector<ll>
using namespace std;
typedef long long ll;

const ll INF = 1e9;
vi dp(1000010, INF);

signed main() { _io
    int n, k;
    cin >> n >> k;

    vi stones(n);
    for (int i = 0; i < n; i++) cin >> stones[i];

    
    dp[0] = 0;

    for (int i = 0; i < n; i++) { 

        for (int j = i + 1; j <= i + k; j++) { 

            if (j < n)
                dp[j] = min(dp[j], dp[i] + abs(stones[j] - stones[i]));

        }

    }

    cout << dp[n - 1] << endl;
}