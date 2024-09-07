#include <bits/stdc++.h>
#define _io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;

int main(){ _io
    string input; 
    getline(cin,input);

    cout << " ";
    for(int i=1;i<=input.size()+2;i++){
        cout << "_";
    }
    cout << "\n";
    cout << "< " << input << " >\n";
    cout << " ";
    for(int i=1;i<=input.size()+2;i++){
        cout << "=";
    }
    cout << "\n";

    cout << "        \\   ^..^      /" << "\n";
    cout << "         \\  /_/\\_____/" << "\n";
    cout << "               /\\   /\\" << "\n";
    cout << "              /  \\ /  \\" << "\n";
}

