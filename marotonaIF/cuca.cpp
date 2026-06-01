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

int main() { _io
    string p; cin >> p;
    int n; cin >> n;    

    vector<string> nomes(n);
    for (auto& nome : nomes) cin >> nome;

    int m; cin >> m;

    vector<string> sobrenomes(m);
    for (auto& sobrenome : sobrenomes) cin >> sobrenome;

    unordered_map<string, int> sufixo_count;

    for (const auto& nome : nomes) {
        for (int i = 0; i < nome.size(); ++i) {
            string sufix = nome.substr(i);
            sufixo_count[sufix]++;
        }
    }

    long long combinacoes = 0;

    for (const auto& sobrenome : sobrenomes) {
        for (int i = 1; i <= sobrenome.size(); ++i) {
            string prefix = sobrenome.substr(0, i);
            if (prefix.size() > p.size()) continue;

        
            if (p.substr(0, prefix.size()) == prefix) {
                string sufix_necessario = p.substr(prefix.size());
                if (sufixo_count.find(sufix_necessario) != sufixo_count.end()) {
                    combinacoes += sufixo_count[sufix_necessario];
                }
            }
        }
    }

    cout << combinacoes << '\n';
    return 0;
}
