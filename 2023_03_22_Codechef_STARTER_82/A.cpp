#include <bits/stdc++.h>
using namespace std;

const int N = 5500;
int a[N], fa[N][2], dp[N][N], p[N];
long long sum[N][2];

vector<int> v[N];

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    HLD(int n) : n(n), siz(n), top(n), dep(n), parent(n, -1), in(n), out(n), seq(n), adj(n) {}
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void init(int root = 0) {
        top[root] = root;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    int cur = 0;
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
};

void dfs(int u, int f, int type, long long s) {
	sum[u][type] = s + p[u];
	for (auto k : v[u])
		if (k != f) {
			fa[k][type] = u;
			dfs(k, u, type, sum[u][type]);
		}
}

int func(int x, int y) {
	if (~dp[x][y]) return dp[x][y];
	if (fa[x][0] && v[x].size() == 1 || fa[y][1] && v[y].size() == 1)
		return dp[x][y] = sum[x][0] > sum[y][1];
	int mx = 0;
	for (auto u : v[x])
		if (u != fa[x][0]) {
			int mn = 1e9;
			for (auto h : v[y])
				if (h != fa[y][1])
					mn = min(mn, func(u, h) + (sum[x][0] > sum[y][1]));
			mx = max(mx, mn);
		}
	return dp[x][y] = mx;
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, a, b; cin >> n >> a >> b;
		HLD hld(n);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i <= n; i++) cin >> p[i];
		for (int i = 1; i < n; i++) {
			int x, y; cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = -1;
		fa[a][0] = fa[b][1] = 0;
		dfs(a, 0, 0, 0);
		dfs(b, 0, 1, 0);
		printf("%d\n", func(a, b));
	}
	return 0;
}
