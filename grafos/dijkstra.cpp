#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _io ios::sync_with_stdio(0);cin.tie(0);

const int MAXN = 2010;
const ll inf = 1e18;
vector<pair<ll,ll>> gr[MAXN];
vector<ll> distH,distS,distG;
int n,m,t,s,g,h,dest[MAXN];


vector<ll> dijkstra(int st){
    vector<ll> dist(n+1,inf);
    
    dist[st] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,st});

    while(pq.size()){
        auto [d,v] = pq.top();
        pq.pop();

        if(d > dist[v]) continue;

        for(auto [w,u]:gr[v]){
            
            if(dist[v]+w < dist[u]){
                dist[u] = dist[v]+w;
                pq.push({dist[u],u});

            }
        }
    }

    return dist;

}

int main(){ _io
    int c;
    cin >> c;
    while(c--){
        
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        ll w=-1;
        for(int i=1;i<=m;i++){
            ll a,b,c;
            cin >> a >> b >> c;
            if((a==g && b == h) || (a==h && b == g)) w = c;
            gr[a].push_back({c,b});
            gr[b].push_back({c,a});
        }
        // cout << "W(g,h): " << w << endl;

        for(int i=1;i<=t;i++) cin >> dest[i];

        distS = dijkstra(s);
        distG = dijkstra(g);
        distH = dijkstra(h);

        // cout << "Dist s->g: " << distG[s] << endl;
        // cout << "Dist h->" << dest[1] << ": " << distH[dest[1]] << endl;

        set<ll> resp;
        for(int i=1;i<=t;i++){

            ll via1 = distS[g] + w + distH[dest[i]];
            ll via2 = distS[h] + w + distG[dest[i]];

            if(distS[dest[i]] == via1 || distS[dest[i]] == via2){
                resp.insert(dest[i]);
            }
        }

        for(auto x:resp) cout << x << " ";
        cout << endl;

        for(int i=1;i<=n;i++) gr[i].clear();

    }
    return 0;
}



void solve(){
    int ans=0;
    cin >> n >> k >> p >>m;
    forn(i,n){
        cin >> a[i];
        if(i<=k)
            st.insert(a[i]);
        else    
            q.push(a[i]);
    }

    int cost=0;
    int pCard=p, valWin = a[p];
    if(p<=k){
        cost += a[p];
        auto it = st.find(a[p]);
        st.erase(it);
        q.push(a[p]);
        p=n-k; //pos p na ultima pos na fila
    }else
        p = p-k; //pos p em uma pos<n na fila
    

    while(cost<=m){

        if(pCard>k){
            int menor = *st.begin();
            cost+=menor;
            st.erase(st.begin());
            q.push(menor);
            st.insert(q.front());
            q.pop();
            p--;
            pCard = max(1,pCard-1);
        }
        
        else{
            cost+=valWin;
            ans++;

            auto it = st.find(a[p]);
            q.push(*it);
            st.erase(it);
            st.insert(q.front());
            q.pop();
            p = n-k;
            pCard=n;

        }


    }
    
    cout << ans << endl;

}