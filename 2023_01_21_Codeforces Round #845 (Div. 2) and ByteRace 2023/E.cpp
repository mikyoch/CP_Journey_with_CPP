#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, m; scanf("%d%d", &n, &m);
		vector<array<int, 3>> e(m);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < 3; j++) scanf("%d", &e[i][j]);
		int st = 0, ed = 1e9 + 5;
		auto can = [&] (int lim) {
			vector<int> fa(n + 1);
			function<int(int)> find = [&] (int u) {
				if (!fa[u]) return u;
				return fa[u] = find(fa[u]);
			};
			auto merge = [&] (int u, int v) {
				u = find(u);
				v = find(v);
				if (u != v) fa[u] = v;
			};
			for (int i = 0; i < m; i++) {
				int u = e[i][0], v = e[i][1], w = e[i][2];
				if (w <= lim) merge(u, v);
			}
			vector<int> deg(n + 1);
			for (int i = 0; i < m; i++) {
				int u = e[i][0], v = e[i][1], w = e[i][2];
				if (w > lim) {
					u = find(u);
					v = find(v);
					if (u != v) deg[v]++;
				}
			}
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (!fa[i] && !deg[i]) cnt++;
			}
			return cnt < 2;
		};
		if (!can(ed)) {
			puts("-1");
			continue;
		}
		while (st < ed) {
			int mid = (st + ed) / 2;
			if (!can(mid)) st = mid + 1;
			else ed = mid;
		}
		printf("%d\n", st);
	}
	return 0;
}
