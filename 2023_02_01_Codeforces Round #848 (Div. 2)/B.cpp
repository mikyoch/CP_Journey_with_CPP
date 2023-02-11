#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, m, d; scanf("%d%d%d", &n, &m, &d);
		vector<int> p(n + 1);
		for (int i = 1; i <= n; i++) {
			int k; scanf("%d", &k);
			p[k] = i;
		}
		vector<int> a(m);
		int ans = INT_MAX;
		for (int i = 0; i < m; i++) {
			scanf("%d", &a[i]);
			a[i] = p[a[i]];
			if (i) {
				ans = min(ans, a[i] - a[i - 1]);
				if (d + 2 <= n) ans = min(ans, a[i - 1] + d + 1 - a[i]);
			}
		}
		printf("%d\n", max(ans, 0));
	}
	return 0;
}

