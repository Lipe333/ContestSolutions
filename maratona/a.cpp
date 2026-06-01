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
    string atunda;
    string s;

    while(getline(cin,atunda) && getline(cin,s) ){
        string ans;

        s.erase(s.find_last_not_of(" \n\r\t") + 1);

        //cout << s << endl;
        if(s == "Sim, vai entender!") ans = "facochero";

        if(s == "E lindo dizer!") ans = "suricato";

        if(s == "Os seus problemas voce deve esquecer!") ans = "leao";

        cout << ans << endl;
    }

    return 0;
}