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
    int n;
    string s; 
    cin >> n >> s;

    int freq[256]={0};
    for(int i=0;i<s.size();i++) freq[s[i]]++;

     for(int i=1;i<=n-2;i++){
        //cout << s[i] << " " << freq[s[i]] << endl;
        if(freq[s[i]]>1){
            cout << "Yes" << endl;
            return;
        }
     }

     cout << "No" << endl;

}

int main(){ _io
    cin >> t;
    while(t--)
        solve();
    return 0;
}