#include <bits/stdc++.h>
using namespace std;

#define MX 2050
vector<int> g[MX];
bool vis[MX];
bool f[MX][MX];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v);
		f[u][v] = true;
	}
	int res = 0;
	function<void(int)> dfs = [&] (int u) {
		vis[u] = true;
		for (int v : g[u]) {
			if (!vis[v]) dfs(v);
		}
	};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) vis[j] = 0;
		dfs(i);
		for (int j = 1; j <= n; j++)
			if (vis[j] && !f[i][j] && i != j) res++;
	}
	printf("%d\n", res);
	return 0;
}

