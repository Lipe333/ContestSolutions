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

int main(){ _io

    cin >> n;
    int life = n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x<15) continue;
        else if(x>=15 && x<20) life--;
        else if(x==20) life-=2;
    }   

    cout << (life<=0 ? "O BRUTO FOI DERROTADO":"O BRUTO ESTA VIVO TPK PARA O GRUPO") << endl;

    return 0;
}