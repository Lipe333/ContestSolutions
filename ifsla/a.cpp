#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(),x.end()

int n;
map<string,int> m;

vector<string> ord = {"Abigail","Sebastian","Penny","Sam","Leah","Harvey","Haley","Maru","Alex","Emily"};

int main(){ _io

    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        int a;
        cin >> s >> a;
        m[s]+=a;
    }

    for(auto s:ord){
        if(m.count(s)>0 && m[s]>=250){
            if(m[s]>2000) m[s]=2000;

            cout << s << " " << m[s]/250 << endl;
        }
    }

    return 0;
}