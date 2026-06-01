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


/**
 * Resolução do problema Foreign Language: https://codeforces.com/gym/105200/problem/F
 */

string a,b;
ll n,m,insert,remv,modify;
ll dp[2010][2010];

ll mMin(ll a, ll b, ll c){
    return min(a,min(b,c));
}

ll solve(string str1, string str2){

    for(int i=0;i<=n;i++){
        for (int j = 0;j<=m;j++){
            
            if(i==0) dp[i][j] = j*insert; // j * custo de inserir
            else if(j==0) dp[i][j] = i*remv; // i * custo de remover
            else if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1];  // se deu match o custo nao muda
            else{
                dp[i][j] = mMin(dp[i][j-1]+insert, 
                                dp[i-1][j]+remv,
                                dp[i-1][j-1]+modify);
            }

        }
        
    }

    return dp[n][m];

}


int main(){ _io

    cin >> n >> m >> insert >> remv >> modify >> a >> b;
    cout << solve(a,b) << endl;

}