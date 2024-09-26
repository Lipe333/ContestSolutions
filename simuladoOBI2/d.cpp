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

int main() { _io
    
    string s;
    ll total = 0;
    cin >> s;
    ll sz = s.size();
    
    vector<ll> pref(sz), suff(sz);
    
    for (int i = 1; i < sz; i++) {
        suff[i] = suff[i - 1]; 
        if (s[i] == 'v' && s[i - 1] == 'v') {
            suff[i] += 1;  
        }
    }
    
    for (int i = sz - 2; i >= 0; i--) {
        pref[i] = pref[i + 1];  
        if (s[i] == 'v' && s[i + 1] == 'v') {
            pref[i] += 1;  
        }
    }
    
    for (int i = 0; i < sz; i++) {
        if (s[i] == 'o' && suff[i] && pref[i]) {
            total += (suff[i] * pref[i]); 
        }
    }
    

    cout << total << endl;

    return 0;
}

