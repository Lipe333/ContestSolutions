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

int t;


int main(){ _io
    cin >> t;

    while(t--){
        int ans=INT_MAX;
        int a, b; cin >> a >> b;
        for(int c=a; c<=b; c++){
            ans=min(ans,((c-a)+(b-a)));
        }
        cout << ans << endl;
    }

    return 0;
}