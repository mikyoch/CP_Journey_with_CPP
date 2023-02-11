#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> g(n, -1);
		vector<int> ideg(n);
		for (int i = 0; i < n; i++) {
			int k; scanf("%d", &k);
			if (i + k >= 0 && i + k < n) g[i] = i + k, ideg[i + k]++;
		}
		int id = 1;
		vector<int> vis(n);
		vector<bool> good(n);
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			int u = g[i];
			vector<int> vec;
			vec.push_back(i);
			set<int> s;
			while (true) {
				if (u < 0 || u == i) {
					for (int v : vec) {
						vis[v] = id;
						if (u == i) good[v] = true;
					}
					id++;
					break;
				}
				if (vis[u]) {
					bool sok = false;
					if (s.count(u)) sok = true;
					for (int v : vec) vis[v] = vis[u], good[v] = good[u] | sok;
					break;
				}
				s.insert(u);
				vis[u] = id;
				vec.push_back(u);
				u = g[u];
			}
		}
		int gc = 0;
		long long sub = 0;
		for (int i = 0; i < n; i++) gc += good[i];
		if (good[0]) {
			int oc = 0;
			for (int i = 0; i < n; i++) oc += vis[i] == vis[0];
			sub = 1ll * gc * oc;
			sub += 1ll * (n - oc) * (2 * n + 1);
		}
		else {
			vector<int> w(n);
			queue<int> q;
			for (int i = 0; i < n; i++) {
				w[i] = 1;
				if (!ideg[i]) q.push(i);
			}
			while (q.size()) {
				int u = q.front(); q.pop();
				int v = g[u];
				if (v >= 0) {
					ideg[v]--;
					w[v] += w[u];
					if (!ideg[v]) q.push(v);
				}
			}
			for (int u = 0; u >= 0; u = g[u]) {
				sub += gc + w[u];
			}
		}
		printf("%lld\n", 1ll * n * (2 * n + 1) - sub);
	}
	return 0;
}
