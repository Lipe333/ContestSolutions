#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vll vector<long long>
#define mk make_pair
using namespace std;
typedef long long ll;

ll countLessEqual(int x, int n) {
    ll count = 0;
    for (int i = 1; i <= n; i++) {
        count += min(x / i, n);
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int low = 1, high = n * n, mid;
    int m_index = (high) / 2 + 1;
    
    while (low < high) {
        mid = low + (high - low) / 2;
        if (countLessEqual(mid, n) < m_index) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << low << endl;
    return 0;
}