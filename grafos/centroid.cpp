int n,m;
vi g[maxn];
int a[maxn], vis[maxn], sz[maxn];

int dfs(int u, int p){
    vis[u] = true;
    sz[u] = 1;
    for(auto v:g[u]){
        if(v != p && !vis[v])
            sz[u] += dfs(v,u);
    }
    return sz[u];
}

int centroid(int u, int p=-1, int size=-1) {
	if (size == -1) size = sz[u];
	for (int i : g[u]) if (i != p) if (sz[i] > size/2)
		return centroid(i, u, size);
	return u;
}
