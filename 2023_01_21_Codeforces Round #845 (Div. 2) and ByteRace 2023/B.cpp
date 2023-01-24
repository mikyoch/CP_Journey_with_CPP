#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		int res = 1;
		const int mod = 1000000007;
		for (int i = 1; i <= n; i++) res = 1ll * res * i % mod;
		res = 1ll * res * n % mod * (n - 1) % mod;
		printf("%d\n", res);
	}
	return 0;
}
