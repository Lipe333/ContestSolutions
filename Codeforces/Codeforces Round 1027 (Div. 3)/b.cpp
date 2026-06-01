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
    int n,k;
    string s;

    cin >> n >> k >> s;

    int nums0=0,nums1=0;
    for(int i=0;i<n;i++){
            if(s[i]=='1') nums1++;
            else nums0++;
    }

    //cout << nums0 << " " << nums1 << endl;

    
    int maxParesBons = (nums0/2)+(nums1/2);
    int minParesBons = abs(nums0-nums1)/2;

    cout << minParesBons << " " << k << " " << maxParesBons << endl;

    if(k>=minParesBons && k<=maxParesBons)
        cout << "YES\n";
    else
        cout << "NO\n";
    

}


int main(){ _io

    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}