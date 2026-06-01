#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define all(x) x.begin(), x.end()
 
#define _io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct Node {
    int minVal;
    int maxVal;
    int indexMin;
    int indexMax;
};

struct segtree {
    int size;
    vector<Node> tree;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, {INT_MAX, INT_MIN,-1,-1}); 
    }

    Node merge(Node left, Node right) {
        int newMin = min(left.minVal, right.minVal);
        int newMax = max(left.maxVal, right.maxVal);
        
        int newIndexMin = (left.minVal <= right.minVal) ? left.indexMin : right.indexMin;
        int newIndexMax = (left.maxVal >= right.maxVal) ? left.indexMax : right.indexMax;
    
        return {newMin, newMax, newIndexMin, newIndexMax};
    }
    

    void build(vi& vet, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)vet.size()) {
                tree[x] = {vet[lx], vet[lx],lx,lx};
            }
            return;
        }
        int mid = (lx + rx) / 2;
        build(vet, 2 * x + 1, lx, mid);
        build(vet, 2 * x + 2, mid, rx);

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vi& vet) {
        build(vet, 0, 0, size);
    }

    Node query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return (Node){INT_MAX, INT_MIN,-1,-1}; // no sobreposição
        if (lx >= l && rx <= r) return tree[x]; //  dentro do intervalo

        int mid = (lx + rx) / 2;
        Node s1 = query(l, r, 2 * x + 1, lx, mid);
        Node s2 = query(l, r, 2 * x + 2, mid, rx);

        return merge(s1, s2);
    }

    Node query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    _io
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        vi arr(n); 
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        segtree st;
        st.init(n);
        st.build(arr);
        
        int q; cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r; 

            Node res = st.query(l-1, r);

            if (res.minVal == res.maxVal) {
                cout << -1 << " " << -1 << "\n";
            } else {
                int i1 = res.indexMin + 1;
                int i2 = res.indexMax + 1;
        
                if (i1 != i2)
                    cout << i1 << " " << i2 << "\n";
                else
                    cout << i1 << " " << (i1 + 1) << "\n";
            }
        }

        if (t > 0) cout << "\n";
    }

    return 0;
}