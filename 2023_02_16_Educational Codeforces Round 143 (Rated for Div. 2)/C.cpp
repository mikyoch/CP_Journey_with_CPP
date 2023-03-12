#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<long long> a(n + 1), b(n + 1), add(n + 1), sub(n + 1);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &b[i]);
			b[i] += b[i - 1];
		}
		long long cur = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			int p = upper_bound(b.begin() + i, b.end(), a[i] + b[i - 1]) - b.begin();
			if (p <= n) {
				sub[p]++;
				add[p] += min(a[i] + b[i - 1] - b[p - 1], b[p] - b[p - 1]);
			}
			cnt++;
			cnt -= sub[i];
			printf("%lld%c", cnt * (b[i] - b[i - 1]) + add[i], " \n"[i == n]);
		}
	}
	return 0;
}

