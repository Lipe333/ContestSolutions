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

int main(){ _io
    int t; cin >> t;

    while(t--){
        int n,k; cin >> n >>k;

        vi v(n);

        for(int i=0;i<n;i++) cin >> v[i];

        int ronbins_gold=0;
        int ans=0;
        for(auto& i:v){
            if(i>=k) {
                ronbins_gold+=i;
                i-=i;
            }else{
                if(ronbins_gold>0 && i==0){
                    ronbins_gold--;
                    i++;
                    ans++;
                }
            }
        }

        cout << ans << endl;

    }

}