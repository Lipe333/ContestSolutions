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

const int inf = 1e6;

int t;

void printAns(vi& v){
    for(auto& x:v){
        cout << x;
    }
    cout << endl;
}

void solve(){

    int n;
    cin >> n;

    vi v(n);
    
    for(auto& x:v) {
        cin >> x;
    }

    vi ans(n,0);

    ans[0] = 1; 
    int mn = v[0];
    for (int i=1;i<n;++i) {
        if (v[i] <= mn) { 
            ans[i] = 1;
        }
        mn = min(mn, v[i]);
    }
    
    ans[n-1] = 1; 
    int mx = v[n-1];
    for (int i=n-2;i>=0;--i) {
        if (v[i] >= mx) { 
            ans[i] = 1;
        }
        mx = max(mx, v[i]);
    }

    printAns(ans);


}

int main(){ _io

    cin >>t;

    while(t--){
        solve();
    }

    return 0;
}