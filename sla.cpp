#include <bits/stdc++.h>

using namespace std;
 
int main() {
    
    // quatro inteiros representando a hora de inicio e fim do jogo
    int a,b,c,d; cin >> a >> b >> c >> d;
    
    int h=0,min=0;
    
    if(c == a && d == b){
        h = 24;
    }else{
        min = d-b;
        if(min<0){
            cout << "OSHI\n";
            min += 60;
            c--;
        }
        h = c-a;
        if(h<0){
            h+=24;
        }

    }
    
    cout << "O JOGO DUROU " << h << " HORA(S) E " << min << " MINUTO(S)\n";
    
    return 0;
}