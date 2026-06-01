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

int t;

void solve(){
    string s;
    cin >> s;

    int ano = stoi(s);
    int sum = sqrt(ano);

    if (sum * sum != ano) {
        cout << -1 << endl;
        return;
    }

    cout << 0 << " " << sum << endl;


}

int main(){ _io

    cin >> t;
    cin.ignore();

    while(t--){
        solve();
    }   

    return 0;
}