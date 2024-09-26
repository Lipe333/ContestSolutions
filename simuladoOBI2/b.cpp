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
#define MAX 1e9


int dp[1001][101]; 
bool used[101];    
vi notas;


bool subsetSum(int sum, int idx, int m) {
    
    if (sum == 0) return true;

    
    if (idx >= m || sum < 0) return false;

    
    if (dp[sum][idx] != -1) return dp[sum][idx];

    bool pegar = false;

    
    if (!used[idx] && sum >= notas[idx]) {
        used[idx] = true;
        pegar = subsetSum(sum - notas[idx], 0, m); 
        used[idx] = false; 
    }

    
    bool n_pegar = subsetSum(sum, idx + 1, m);

    
    return dp[sum][idx] = pegar || n_pegar;
}

int main() {
    int n, m;
    cin >> n >> m;

    vi salarios(n); 
    notas.resize(m);         

    
    for (int i = 0; i < n; i++) {
        cin >> salarios[i];
    }

    
    for (int i = 0; i < m; i++) {
        cin >> notas[i];
    }

    
    for (int i = 0; i < n; i++) {
        
        memset(dp, -1, sizeof(dp));
        memset(used, false, sizeof(used));

        if (!subsetSum(salarios[i], 0, m)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
