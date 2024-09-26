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
#define MAX 1000010

ll freq[MAX];

int sum_digs(ll x){
    ll res = 0;

    while(x>0){
        res += x%10;
        x/=10;
    }
    return res;
}

int main(){ _io

    ll n, k; cin >> n >> k;
    
    vi v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        freq[v[i]]++;
    }

    for(int i=MAX;i>=0;i--){
        int extract = sum_digs(i);

        ll ops = min(k,(ll)freq[i]);

        freq[i] -= ops; 

        freq[i-extract]+=ops;

        k -= ops;

        if(k==0){
            cout << extract << "\n";
            return 0;
        }

    }
    cout << 0 << endl;
    return 0;
}