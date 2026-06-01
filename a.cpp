#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for(int i = 1; i <= n; i++)
#define endl '\n'
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()

const int MAXN = 2010;
int n;

void printv(){
    forn(i,n)
        cout << a[i] << " ";
    cout << endl;
}

void moveBlocos(int i, int j){
    vi aux = {a[i],a[i+1],a[i+2]};
    a.erase(a.begin()+i,a.begin()+i+3);
    a.insert(a.begin()+j,all(aux));
}

void moveBlocos2(){

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    vi a(n+1);
    forn(i,n)
        cin >> a[i];

    // printv();
    // moveBlocos(min(10-2,9),1);
    // printv();

    if(is_sorted(all(a))){
        cout << 0 << endl;
        return 0;
    }

    for(int i=n;i>=0;i--){
        
    }
  
    return 0;
 
}