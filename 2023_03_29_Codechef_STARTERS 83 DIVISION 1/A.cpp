#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, q; scanf("%d%d", &n, &q);
		vector<int> a(n), pos(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			pos[a[i]] = i;
		}
		vector<pair<int, int>> seg(n);
		for (int i = 0, mn = n, mx = 0; i < n; i++) {
			mn = min(mn, pos[i]);
			mx = max(mx, pos[i]);
			seg[i] = {mn, mx};
		}
		while (q--) {
			int l1, l2, m1, m2; scanf("%d%d%d%d", &l1, &l2, &m1, &m2);
			auto get = [&] (int l, int t) {
				long long res = 0;
				if (l > n || t >= n) return res;
				if (t < 0) {
					res += 1ll * (n - l + 1) * (n - l + 2) / 2;
					return res;
				}
				int st = seg[t].first;
				int ed = seg[t].second;
				l = max(ed - st + 1, l);
				int e1 = max(l - 1, ed);
				int e2 = max(min(st + l - 1, n - 1), ed);
				res += 1ll * (n - e1) * (e1 - l + 1 + 1);
				int s = e1 - l + 1 + 1;
				if (s <= st) {
					e1 = n - s - l + 1;
					e2 = max(0, e1 - st + s);
					res += 1ll * (e1 + e2) * (e1 - e2 + 1) / 2;
				}
				return res;
			};
			long long cnt = get(l1, m1 - 1) - get(l2 + 1, m1 - 1) - get(l1, m2) + get(l2 + 1, m2);
			printf("%lld\n", cnt);
		}
	}
	return 0;
}
/*
1
4 1000
2 0 1 3
1 2 1 3
*/
