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

int main(){ _io
    int t; cin >> t;

    while(t--){
        ll n,k; cin >> n >> k;
        ll i = n-k+1;
        ll  even=0; // odd->par even->impar

        even = ((n+1) / 2)-(i/2);
        /* for(int j=i;j<=n;j++){
            if(j%2==0) odd++;
            else even++;
        } */

        string ans;
        if(even%2==0) ans="YES\n";
        else ans="NO\n";

        cout << ans; 

    }
}