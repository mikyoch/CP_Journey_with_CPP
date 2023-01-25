#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> a(n);
		long long sum = 0;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
		long long cur = 0, ans = 0;
		for (int i = 0; i < n - 1; i++) {
			cur += a[i];
			ans = max(ans, __gcd(cur, sum - cur));
		}
		printf("%lld\n", ans);
	}
	return 0;
}