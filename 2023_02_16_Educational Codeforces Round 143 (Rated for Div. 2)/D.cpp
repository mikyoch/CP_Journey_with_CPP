#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int ans = 1;
	const int mod = 998244353;
	for (int i = 0; i < n / 3; i++) {
		int a[3];
		for (int j = 0; j < 3; j++) scanf("%d", a + j);
		sort(a, a + 3);
		if (a[0] == a[1] && a[1] == a[2]) ans = ans * 3ll % mod;
		else if (a[0] == a[1]) ans = ans * 2ll % mod;
	}
	int tmp = 1;
	for (int i = 1; i <= n / 3; i++) ans = 1ll * ans * i % mod;
	for (int i = 1; i <= n / 6; i++) tmp = 1ll * tmp * i % mod;
	auto power = [&] (int a, int b) {
		int res = 1;
		for (; b; b >>= 1) {
			if (b & 1) res = 1ll * res * a % mod;
			a = 1ll * a * a % mod;
		}
		return res;
	};
	tmp = power(tmp, mod - 2);
	ans = 1ll * ans * tmp % mod * tmp % mod;
	printf("%d\n", ans);
	return 0;
}
