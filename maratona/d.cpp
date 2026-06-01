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
#define all(a) a.begin(),a.end()
#define MAX 1e9

int main(){ _io

    int n; cin >> n;

    vector<pair<int,string>> alunos(n);

    for(auto& a:alunos) {
        cin >> a.second >> a.first; 
    }

    sort(all(alunos));

    int l = 0, r = n - 1;
    vi sumNotas; 

    while (l < r) {
        int somaNotas = alunos[l].f + alunos[r].f;
        sumNotas.pb(somaNotas);
        l++; 
        r--;
    }

    int diffSumNotas = 0;
    
    if (sumNotas.size() > 1) {
        sort(sumNotas.begin(), sumNotas.end());
        diffSumNotas = sumNotas.back() - sumNotas.front();
    }

    cout << diffSumNotas << endl;

    l = 0, r = n - 1;
    while (l < r) {
        cout << alunos[l].s << " " << alunos[l].f << " " 
             << alunos[r].s << " " << alunos[r].f << endl;
        l++; 
        r--;
    }

}