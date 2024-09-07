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

int t;

int main(){ _io
    cin >> t;

    while(t--){
        int n; cin >> n;
        char beatmap[n][4];

        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                cin >> beatmap[i][j];
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<4;j++){
                if(beatmap[i][j]=='#'){
                    cout << j+1 << " ";
                }
            }
        }
        cout << endl;

    }

    return 0;
}