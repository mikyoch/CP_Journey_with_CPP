#include <bits/stdc++.h>
using namespace std;

const int MX = 200050;
int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<vector<array<int, 2>>> g(MX);
	vector<array<int, 2>> e(MX);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back({v, i});
		g[v].push_back({u, i});
		e[i] = {u, v};
	}
	int k; scanf("%d", &k);
	vector<bool> must(m + 1);
	for (int i = 0; i < k; i++) {
		int u; scanf("%d", &u);
		must[u] = true;
	}
	vector<bool> vis(MX);
	vector<int> dp(MX);
	auto fuck = must;
	int ic = 0;
	int tot = 0;
	function<int(int, int, int)> dfs = [&] (int u, int ui, int p) {
		int tu = dp[u];
		for (auto it : g[u]) {
			int v = it[0];
			int vi = it[1];
			if (v == p) continue;
			if (vis[v]) {
				if (dp[v] < dp[u]) {
					tot++;
					if (must[vi]) fuck[vi] = false, ic++;
					tu = min(tu, dp[v]);
				}
			} else {
				tot++;
				vis[v] = true;
				dp[v] = dp[u] + 1;
				tu = min(tu, dfs(v, vi, u));
			}
		}
		if (tu < dp[u] && must[ui]) ic++, fuck[ui] = false;
		return tu;
	};
	vis[1] = true;
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++) vis[i] = 0;
	vector<int> fc(MX);
	int ftot = 0;
	for (int i = 1; i <= m; i++) ftot += fuck[i];
	assert (ftot == k - ic);
	bool ok = false;
	function<int(int)> func = [&] (int u) {
		int mx0 = 0, mx1 = 0;
		for (auto it : g[u]) {
			int v = it[0];
			int vi = it[1];
			if (vis[v]) continue;
			vis[v] = true;
			int cur = fuck[vi] + func(v);
			if (mx0 < cur) {
				mx1 = mx0;
				mx0 = cur;
			} else if (mx1 < cur) {
				mx1 = cur;
			}
		}
		if (mx0 + mx1 == ftot) ok = true;
		return mx0;
	};
	vis[1] = true;
	func(1);
	puts(ok ? "Yes" : "No");
	return 0;
}
