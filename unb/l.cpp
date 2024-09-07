#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

int main(){ _io
    string pai,mae,filho;
    cin >> pai >> mae >> filho;

    for(int i=0; i<filho.size(); i++){
        if(filho[i] != pai[i] && filho[i] != mae[i]){
            cout << "Orra meu...\n";
            return 0;
        }
    }
    cout << "Herdou!\n";

}