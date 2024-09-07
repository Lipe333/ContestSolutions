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

int main() { _io
    int N;
    cin >> N;
    
    vll a(N);
    vll bit_count(31, 0);
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        for (int j = 0; j < 31; ++j) {
            if (a[i] & (1 << j)) {
                bit_count[j]++;
            }
        }
    }
    
    vll result(N, 0);
    for (int j = 30; j >= 0; --j) {
        for (int i = 0; i < N && bit_count[j] > 0; ++i) {
            if (!(result[i] & (1 << j))) {
                result[i] |= (1 << j);
                bit_count[j]--;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}