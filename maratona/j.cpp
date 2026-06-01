#include <bits/stdc++.h>
using namespace std;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF INT_MAX

int dp[1010][110]; 
int o[1010]; 
int l[1010]; 


int solve(int i, int k) {
    if (k == 0) return 0; 
    if (k < 0 || i < 0) return INF; 

    
    if (dp[i][k] != -1) return dp[i][k];


    int minCompetitions = INF;

    minCompetitions = solve(i - 1, k);

    for (int j = 1; j <= l[i]; j++) { 
        int newMedals = j * o[i]; 
        if (newMedals <= k) { 
            int competitionsNeeded = solve(i - 1, k - newMedals);
            if (competitionsNeeded != INF) {
                minCompetitions = min(minCompetitions, competitionsNeeded + j);
            }
        }
    }

    dp[i][k] = minCompetitions; 
    return dp[i][k];
}

int main() {
    _io
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> o[i]; 
    }
    for (int i = 0; i < M; i++) {
        cin >> l[i]; 
    }

    memset(dp, -1, sizeof(dp)); 

    int ans = solve(M - 1, N); 

    if (ans == INF) {
        cout << -1 << endl; 
    } else {
        cout << ans << endl;
    }

    return 0;
}
