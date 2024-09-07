#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define mk make_pair
using namespace std;
typedef long long ll;

int main(){
    _
    ll n,k; cin >> n >> k;
    vll arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    
    ll l = arr[n/2], r = arr[n/2]+k;

    while(l<r){
        ll mid = (l+r+1)/2;
        ll ops=0;
        for(int i=n/2; i<n; i++){
            if(arr[i]<mid) ops+= mid - arr[i];
        }

        if (ops <= k) {
            l = mid; 
        } else {
            r = mid - 1; 
        }
    }

    cout << l << endl;
}