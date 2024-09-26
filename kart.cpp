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
#define INF 1e9

int n;

// Conta o número de inversões
int conta(vi& karts){
    if(karts.size()==1) return 0;
    vi a,b;
    for(int i=0; i<karts.size()/2;i++) a.pb(karts[i]);
    for(int j=karts.size()/2; j<karts.size();j++) b.pb(karts[j]);
    int cont = conta(a)+conta(b);

    a.pb(INF);b.pb(INF);
    int i=0, j=0;
    for(int k=0;k<karts.size();k++){
        if((a[i]<=b[j])){
            karts[k] = a[i++];
        }else{
            cont+=(a.size()-i-1);
            karts[k] = b[j++];
        }
    }
    return cont;
}

// Só printa o vetor pra fins de análise e debug
void printV(vi& v){
    int size=v.size();
    for(int i=0; i<size;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){ _io
    cin >> n;
    vi kart(n);
    for(int i=0;i<n;i++) cin >> kart[i];

    /* int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1;j<n;j++){
            if(kart[i] > kart[j]){
                swap(kart[i],kart[j]);
                ans++;
            }
            //printV(kart); 
        }
    } */
   
    cout << conta(kart) << endl;
}