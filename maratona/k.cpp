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

ll countTrailingZeros(ll n) {
    ll count = 0;
    while (n > 0) {
        n /= 5;
        count += n;
    }
    return count;
}

int main() {
    _io
    ll M;
    cin >> M;

   
    ll left = 0, right = 5 * (M + 1); 
    vll results;


    while (left <= right) {
        ll mid = (left + right) / 2;
        ll zeros = countTrailingZeros(mid);

        if (zeros < M) {
            left = mid + 1; 
        } else if (zeros > M) {
            right = mid - 1;
        } else {
            results.push_back(mid); 
            right = mid - 1; 
        }
    }

    
    left = 0, right = 5 * (M + 1);
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll zeros = countTrailingZeros(mid);

        if (zeros < M) {
            left = mid + 1;
        } else if (zeros > M) {
            right = mid - 1; 
        } else {
            results.pb(mid); 
            left = mid + 1; 
        }
    }

    if (!results.empty()) {
        cout << *min_element(results.begin(), results.end()) << endl;
    } else {
        cout << -1 << endl; 
    }

    return 0;
}
