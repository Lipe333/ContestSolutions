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
#define all2(x) x.rbegin(),x.rend()

const int N = 1009;

// indicar se é hdr ou nao, ja da p fazer isso
// p imagem escuro ev positivos
// p imagem clara ev negativos
// abordar os casos adicionais
// almoço com o escritorio na quarta

vi adj[N];           
int indegree[N];     
int time_to_compile[N]; 

int main() {
    _io;
    int n;
    while (cin >> n) {
        for (int i = 0; i <= n; ++i) {
            adj[i].clear();
            indegree[i] = 0;
            time_to_compile[i] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            int Mi;
            cin >> Mi;
            for (int j = 0; j < Mi; ++j) {
                int dep;
                cin >> dep;
                adj[dep].pb(i);  
                indegree[i]++;    
            }
        }

        queue<int> q;

        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                time_to_compile[i] = 1;  
            }
        }

        int total_time = 0;
        int processed_files = 0; 

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processed_files++;

            total_time = max(total_time, time_to_compile[u]);

            for (int v : adj[u]) {
                
                indegree[v]--;
                
                time_to_compile[v] = max(time_to_compile[v], time_to_compile[u] + 1);

                
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        
        if (processed_files != n) {
            cout << -1 << endl;
        } else {
            cout << total_time << endl;
        }
    }

    return 0;
}