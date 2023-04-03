#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int q; scanf("%d", &q);
		long long l = 0, r = LLONG_MAX >> 2;
		while (q--) {
			int t; scanf("%d", &t);
			int a, b, n;
			auto get = [&] (long long a, long long b, long long h) {
				if (h <= a) return 1ll;
				if (a < b) return (long long)-1;
				return (h - a - 1) / (a - b) + 2;
			};
			if (t == 1) {
				scanf("%d%d%d", &a, &b, &n);
				long long fr = (n >= 2 ? (a - b) * 1LL * (n - 2) + a : 0) + 1;
				long long to = (a - b) * 1LL * (n - 1) + a;
				if (max(fr, l) <= min(to, r)) {
					l = max(fr, l);
					r = min(to, r);
					printf("1 ");
				} else {
					printf("0 ");
				}
			} else {
				scanf("%d%d", &a, &b);
				if (get(a, b, l) != get(a, b, r)) printf("-1 ");
				else printf("%lld ", get(a, b, l));
			}
		}
	}
	return 0;
}

