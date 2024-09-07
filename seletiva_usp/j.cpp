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

int main(){ _io

    int n; cin >> n;
    vll arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr.begin(),arr.end());

    ll P=0, R=LLONG_MIN;
    for(int i=0; i<n; i++){
        if((n-i)*arr[i] > R){
            P=arr[i];
            R=max(R,(n-i)*arr[i]);
        }
    }

    cout << P <<" "<<R<<endl;

}