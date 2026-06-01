#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define forn(i, n) for(int i = 1; i <= n; i++)
#define repi(i,n) for(int i = 0; i < n; i++)
#define endl '\n'
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()

const int maxn = 2e5+10;

ll tam;
ll numero;

int32_t main(){ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tam >> numero;

    ll resp=0;

    while(numero > 0){
        resp += numero % 10;
        numero /= 10;
    }

    cout << resp+numero << '\n';

    return 0;   
       
}