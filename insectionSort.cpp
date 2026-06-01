#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for(int i = 0; i < n; i++)
#define endl '\n'
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()

void printVector(vi& v){
    for(auto x:v) 
        cout << x << " ";
    cout << endl;
}

vi insectionSort(vi& v,int n){

    vi vetor(all(v));

    for(int j=1;j<n;j++){
        int chave=vetor[j];

        int i=j-1;
        while(i>=0 && vetor[i]>chave){
            vetor[i+1] = vetor[i];
            i--;
        }

        vetor[i+1] = chave;
        printVector(vetor);
    }

    return vetor;

}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);

    
    for(auto& x:a)
    cin >> x;
    
    printVector(a);
    
    a = insectionSort(a,n);

    printVector(a);
    
    return 0;   
       
}