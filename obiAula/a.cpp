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
#define rall(x) x.rbegin(),x.rend()

int n;

int main(){
    _io
    cin >> n;
    vi repost(n);
    for(int i=0;i<n;i++){
        cin >> repost[i];
    }

    vi freq(repost.size() + 1, 0);
    int ans = 0;
    int n = repost.size();
    
    for (auto i: repost)  {
        if (i >= n)
            freq[n] += 1;
        else
            freq[i] += 1;
    }
    
    ans = n;
    int sum = freq[n];
    
    while (sum < ans)  {
        ans--;
        sum += freq[ans];
    }

    cout << ans << endl;
}


