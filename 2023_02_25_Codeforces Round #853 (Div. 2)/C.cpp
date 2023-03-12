#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, m; scanf("%d%d", &n, &m);
		vector<int> a(n + 1), cnt(n + m + 1), b(n + m + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			cnt[a[i]] = 1;
			b[a[i]] = m + 1;
		}
		for (int i = 0; i < m; i++) {
			int p, v; scanf("%d%d", &p, &v);
			int u = a[p];
			if (u == v) continue;
			cnt[u]--;
			cnt[v]++;
			if (!cnt[u]) b[u] -= m - i;
			if (cnt[v] == 1) b[v] += m - i;
			a[p] = v;
		}
		long long res = 0;
		for (int i = 1; i <= n + m; i++) res += 1ll * b[i] * (m + 1 - b[i]) + 1ll * b[i] * (b[i] - 1) / 2;
		printf("%lld\n", res);
	}
	return 0;
}
