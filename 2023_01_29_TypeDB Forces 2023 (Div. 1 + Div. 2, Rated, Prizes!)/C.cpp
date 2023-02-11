#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, s; scanf("%d%d", &n, &s);
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		long long r1 = 0, r2 = 0, res = 0;
		int p1 = a[0], p2 = a[0];
		for (int i = 1; i < n - 1; i++) {
			int x = min(s, a[i]);
			int y = a[i] - x;
			if (x > y) swap(x, y);
			r1 += 1ll * p1 * x;
			r2 += 1ll * p2 * y;
			p1 = y;
			p2 = x;
			if (x == y) {
				printf("------- %d\n", i);
				res += min(r1, r2);
				r1 = r2 = 0;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}

