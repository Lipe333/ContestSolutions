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
#define all(a) a.begin(),a.end()
#define MAX 1e9

int main(){ _io
    int n,k; cin >> n >> k;

    vector<pair<int, int>> cobertura;

    for (int i = 0; i < n; i++) {
        int L, R, G;
        cin >> L >> R >> G;
        cobertura.push_back(mp(L, G));    
        cobertura.push_back(mp(R + 1, -G)); 
    }

    sort(all(cobertura));

    

}