#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<vector<int>> g(n + 1);
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int res = 0;
		const int mod = 1000000007;
		function<int(int, int)> dfs = [&] (int u, int p) {
			int h = 0;
			for (int v : g[u]) {
				if (v == p) continue;
				h = max(h, dfs(v, u));
			}
			res = (res + h + 1) % mod;
			return h + 1;
		};
		dfs(1, 0);
		for (int i = 1; i < n; i++) res = (res + res) % mod;
		printf("%d\n", res);
	}
	return 0;
}
