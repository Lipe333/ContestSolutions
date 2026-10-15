#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(),x.end() 
#define sq(x) ((x)*(x))
#define endl "\n"

using pii = pair<int,int>;
using tii = tuple<int,int,int>;

const int maxn = 2e5;
const ll inf = 1e18;

int q,n;

struct Node {
    ll sum;
};

struct SegTree {
    int n;
    vector<Node> t;
    vll lz;

    Node merge(const Node& a, const Node& b) {
        return {a.sum + b.sum};
    }

    // soma v em todo o segmento [lx, rx)
    void apply(int x, int lx, int rx, ll v) {
        t[x].sum += v * (rx - lx);
        lz[x] += v;
    }

    void push(int x, int lx, int rx) {
        if (lz[x]) {
            int m = (lx + rx) / 2;
            apply(2 * x + 1, lx, m, lz[x]);
            apply(2 * x + 2, m, rx, lz[x]);
            lz[x] = 0;
        }
    }

    void build(const vll& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = {a[lx]};
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void init(const vll& a) {
        n = a.size();
        t.assign(4 * n, {0});
        lz.assign(4 * n, 0);
        build(a, 0, 0, n);
    }

    // soma v em [l, r)
    void update(int l, int r, ll v, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return;
        if (l <= lx && rx <= r) {
            apply(x, lx, rx, v);
            return;
        }
        push(x, lx, rx);
        int m = (lx + rx) / 2;
        update(l, r, v, 2 * x + 1, lx, m);
        update(l, r, v, 2 * x + 2, m, rx);
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    // soma em [l, r)
    Node query(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return {0};
        if (l <= lx && rx <= r) return t[x];
        push(x, lx, rx);
        int m = (lx + rx) / 2;
        return merge(query(l, r, 2 * x + 1, lx, m),
                     query(l, r, 2 * x + 2, m, rx));
    }

    void update(int l, int r, ll v) { update(l, r, v, 0, 0, n); }
    Node query(int l, int r) { return query(l, r, 0, 0, n); }
};



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    vll a(n+10);
    for(int i=0;i<n;i++) cin >> a[i];

    SegTree seg;
    seg.init(a);

    while(q--){
        int op;
        cin >> op;

        if(op==1){
            int a,b;
            ll u;
            cin >> a >> b >> u;
            seg.update(a-1,b,u);
        }else{
            int k;
            cin >> k;
             cout << seg.query(k - 1, k).sum << endl;
        }
    }


    return 0;
}
