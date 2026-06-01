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

int t;

void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> x(n);

    int minX = INT16_MAX, maxX = INT16_MIN;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        minX = min(minX,x[i]); maxX = max(maxX,x[i]); 
    }

    int ans = abs(s - minX) + (maxX - minX); 
    ans = min(ans, abs(s - maxX) + (maxX - minX)); 

    cout << ans << endl;
}


int main(){ _io

    cin >> t;
    while(t--)
        solve();


    return 0;
}