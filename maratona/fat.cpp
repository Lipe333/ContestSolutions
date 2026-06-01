#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<long long> fatoriais;  // Vetor para armazenar os fatoriais
    long long fatorial = 1;       // Fatorial inicial
    int n = 0;                    // Inicializando n

    while (fatorial <= 1e9) {
        if (n > 0) {
            fatorial *= n;         // Calcula n! = (n-1)! * n
        }
        fatoriais.push_back(fatorial); // Adiciona o fatorial ao vetor
        n++;                        // Incrementa n
    }

    // Imprime os fatoriais armazenados
    for (size_t i = 0; i < fatoriais.size(); i++) {
        cout << fatoriais[i];
        if (i < fatoriais.size() - 1) {
            cout << ", ";           // Formata a saída
        }
    }
    cout << endl;

    return 0;
}
