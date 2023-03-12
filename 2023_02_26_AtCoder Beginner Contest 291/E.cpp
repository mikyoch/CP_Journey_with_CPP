#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<vector<int>> g(n + 1, vector<int>());
	vector<int> ans(n + 1), ideg(n + 1);
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v);
		ideg[v]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) if (!ideg[i]) { q.push(i); ans[i] = 1; }
	int mx = 1;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			ideg[v]--;
			if (!ideg[v]) { q.push(v); ans[v] = ans[u] + 1; mx = max(mx, ans[v]); }
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!ans[i] || mx != n) { puts("No"); return 0;}
	}
	puts("Yes");
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}

