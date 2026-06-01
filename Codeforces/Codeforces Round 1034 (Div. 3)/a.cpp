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

struct pt{
    int x, y;
    pt operator +(const pt &a){ return {x + a.x, y + a.y}; }
    pt operator -(const pt &a){ return {x - a.x, y - a.y}; }
    int operator *(const pt &a){ return x * a.x + y * a.y; }
    int operator /(const pt &a){ return x * a.y - y * a.x; }
    bool operator <(const pt &a){ 
        if(x != a.x) return x < a.x;
        return y < a.y;
    }
};
 
 
bool colinear(pt a, pt b, pt c){
    return (b - a) / (c - a) == 0;
}
 
int t;

void solve(){

}

int main(){ _io

    cin >> t;
    while(t--)
        solve();

    return 0;
}