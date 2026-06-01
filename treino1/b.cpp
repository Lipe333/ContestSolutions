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

int main(){ _io
    int n,d;
    while(cin >> n >> d && n>0 && d>0){
        int remover = d;
        string num,ans;
        cin >> num;
        
        stack<char> st;

        for(int i=0;i<num.size();i++){
            
            while(!st.empty() && remover>0 && st.top()<num[i]){
                st.pop();
                remover--;
            }
            st.push(num[i]);
        }
        
        while (remover--) st.pop();

        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        reverse(all(ans));

        cout << ans << "\n";

    }
    
}