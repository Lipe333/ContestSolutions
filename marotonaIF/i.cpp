#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define MAX 1e9
#define all(x) x.begin(),x.end()

int main() { _io
    int n, r; 
    cin >> n >> r;

    map<ll, int> dias;

    for (int i = 0; i < r; i++) {
        int q;
        ll a, b;
        cin >> q >> a >> b;
        dias[a]++;    
        dias[b + 1]--;
    }

    ll mquartos = -1, qatuais = 0, mdias = 0;

    for (auto [a,b]:dias){
        int dia = a;
        int mudou = b;

        qatuais += mudou;

        if (qatuais > mquartos)
        {
            mquartos = qatuais;
            mdias = dia;
        }
    }

    cout << mquartos << " " << mdias << endl;

    return 0;
}