#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

// Função para executar o algoritmo de Ford-Fulkerson
int fordFulkerson(vector<vector<int>>& graph, int source, int sink, vector<vector<int>>& residualGraph) {
    int u, v;
    int max_flow = 0;
    vector<int> parent(graph.size());
    
    while (true) {
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;
        
        while (!q.empty()) {
            u = q.front();
            q.pop();
            
            for (v = 0; v < graph.size(); ++v) {
                if (parent[v] == -1 && residualGraph[u][v] > 0) {
                    parent[v] = u;
                    if (v == sink) break;
                    q.push(v);
                }
            }
            if (parent[v] != -1) break;
        }
        
        if (parent[sink] == -1) break;

        int path_flow = INF;
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, residualGraph[u][v]);
        }

        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= path_flow;
            residualGraph[v][u] += path_flow;
        }
        
        max_flow += path_flow;
    }
    
    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, D, M;
    cin >> N >> D >> M;
    
    vector<int> requests(M);
    vector<vector<int>> days(N + 1);
    
    for (int i = 0; i < M; ++i) {
        cin >> requests[i];
        days[requests[i]].push_back(i + 1);  // pedidos são numerados a partir de 1
    }
    
    int totalNodes = N + M + 2;
    vector<vector<int>> graph(totalNodes, vector<int>(totalNodes, 0));
    
    int source = 0, sink = totalNodes - 1;
    
    // Conectar a fonte aos dias
    for (int i = 1; i <= N; ++i) {
        graph[source][i] = 1;
    }
    
    // Conectar os dias aos pedidos possíveis
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < days[i].size(); ++j) {
            int requestId = days[i][j];
            for (int k = i; k <= min(N, i + D); ++k) {
                graph[k][N + requestId] = 1;
            }
        }
    }
    
    // Conectar pedidos ao sumidouro
    for (int i = 1; i <= M; ++i) {
        graph[N + i][sink] = 1;
    }
    
    vector<vector<int>> residualGraph = graph;
    
    // Calcular o fluxo máximo
    int minMachines = fordFulkerson(graph, source, sink, residualGraph);
    
    cout << minMachines << '\n';
    
    vector<vector<int>> schedule(N + 1);
    
    // Construir o cronograma com base no grafo residual
    for (int i = 1; i <= N; ++i) {
        for (int j = N + 1; j < totalNodes; ++j) {
            if (graph[j][i] == 1 && residualGraph[j][i] == 0) {
                schedule[i].push_back(j - N);
            }
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j : schedule[i]) {
            cout << j << ' ';
        }
        cout << "0\n";
    }
    
    return 0;
}
