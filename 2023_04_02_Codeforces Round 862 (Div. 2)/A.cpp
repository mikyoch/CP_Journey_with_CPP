#include <bits/stdc++.h>

using i64 = long long;
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

int main() {
    int n; scanf("%d", &n);
    
    HLD tree(n + 5);
    map<pair<int, int>, int> mp;
    set<pair<int, int>> e;
    for (int i = 0; i < n - 1; i++) {
        int u, v; scanf("%d%d", &u, &v);
        tree.addEdge(u, v);
        mp[make_pair(u, v)] = mp[make_pair(v, u)] = i;
        e.insert(make_pair(u, v));
    }
    tree.init(1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; i++) vec.emplace_back(a[i], i);
    while (e.size()) {
    }
    return 0;
}
