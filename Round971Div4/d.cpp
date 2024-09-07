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
#define MAX (int)2e5

int main() {  _io
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int count_y0 = 0, count_y1 = 0;

        vector<int> y0, y1;

        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            if (y == 0) {
                count_y0++;
                y0.push_back(x);
            } else {
                count_y1++;
                y1.push_back(x);
            }
        }

        int total_triangles = 0;
        
        int size_y0 = y0.size();
        int size_y1 = y1.size();
        
        total_triangles += size_y0 * (size_y0 - 1) / 2 * size_y1;
        total_triangles += size_y1 * (size_y1 - 1) / 2 * size_y0;

        cout << total_triangles << '\n';
    }

    return 0;
}