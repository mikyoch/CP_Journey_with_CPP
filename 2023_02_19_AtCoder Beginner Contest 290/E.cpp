#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<vector<int>> p(n + 1);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		p[k].push_back(i);
	}
	long long res = 0, c = 0;
	for (int i = 1; i <= n; i++) {
		res += 1ll * (n - i + 1) * (i / 2);
		for (int j = 0; j < p[i].size(); j++) {
			int v = p[i][j];
			if (v <= n / 2) {
				int ed = upper_bound(p[i].begin(), p[i].end(), n - v + 1) - p[i].begin();
				ed--;
				if (j <= ed) {
					res -= 1ll * v * (ed - j);
					if (j != ed && p[i][ed] == n - v + 1) res += v;
				} else assert(0);
			}
			else {
				int ed = lower_bound(p[i].begin(), p[i].end(), n - v + 1) - p[i].begin();
				if (ed <= j) {
					res -= 1ll * (n - v + 1) * (j - ed);
				} else assert(0);
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}
