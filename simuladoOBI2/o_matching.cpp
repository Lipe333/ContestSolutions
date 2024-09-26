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
#define MAX 1e9

int dp[30];

vector<vector<int>> mat(21,vector<int>(21)); 


int main(){ _io

    int n = 32;

    // shift a esqerda é igual a multiplicar o numero por 2^n

    //shift a direita é igual a dividir o numero por 2^n
    1 << n;
    n = n >> 2;
    cout << n << endl;

    


}