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

int n,q;
ll dp[1010][8010][5];
int nums[1010];

ll solve(int i, int sum, int qtd) {
    if (qtd == 0 && sum == 0) return 1;
    if (i < 0 || sum < 0 || qtd < 0) return 0;

    if (dp[i][sum][qtd] != -1)
        return dp[i][sum][qtd];

    ll nao_pega = solve(i - 1, sum, qtd),pega=0;
    
    if(sum>=nums[i])
         pega = solve(i - 1, sum - nums[i], qtd - 1);

    return dp[i][sum][qtd] = pega + nao_pega;
}


int main(){ _io
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> nums[i];
        nums[i]+=1000;
    }

    memset(dp,-1,sizeof dp);
    cin >> q;
    while(q--){
        int sum; 
        cin >> sum;
        cout << solve(n-1,sum+4000,4) << endl;
    }

}