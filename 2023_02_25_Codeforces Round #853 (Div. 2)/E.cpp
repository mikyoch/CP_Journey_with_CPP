#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 1; i <= 100; i++) {
		int ed = 100 / i;
		int st = 100 / (i + 1) + 1;
		printf("(%d, %d)\n", st, ed);
	}
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> s(n);
		const int mod = 998244353;
		for (int i = 0; i < n; i++) {
			scanf("%d", &s[i]);
		}
		const int MX = 2 * s[n - 1];
		vector<bool> vis(MX);
		vector<int> sum(MX);
		long long res = 0;
		for (int i = 0; i < n; i++) vis[s[i]] = true;
		for (int i = 1; i < MX; i++) sum[i] = sum[i - 1] + vis[i];
		int T = s[n - 1];
		for (int i = 1; i <= T; i++) {
			if (T % i == 0) {
				for (int j = i; j <= T; j += i)
					if (vis[j]) res = (res + T / i) % mod;
			}
		}
		for (int i = 1; i * i <= T; i++) {
			int a = T / i;
			bool ok = false;
			long long cur = 0;
			long long tmp = res;
			if (i * a != T && i != a) {
				for (int p = 1; p * a <= T; p++) {
					cur += sum[a * p + p] - sum[a * p - 1];
				}
			}
			res = (res + cur * i) % mod;
			if (i * i != T) {
				int ed = T / i - (T % i == 0);
				int st = T / (i + 1) + 1;
				long long t = (st + ed) * (ed - st + 1) / 2 % mod;
				cur = 0;
				for (int j = 1; j < i; j++) cur += sum[i * j + j] - sum[i * j - 1];
				cur += sum[T] - sum[i * i - 1];
				res = (res + cur * t) % mod;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
/*
4
3
1 2 4
4
1 2 7 9
4
344208 591000 4779956 5403429
5
1633 1661 1741 2134 2221
*/
