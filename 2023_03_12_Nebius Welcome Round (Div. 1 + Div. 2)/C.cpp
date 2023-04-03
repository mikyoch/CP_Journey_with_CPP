#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, x, p; scanf("%d%d%d", &n, &x, &p);
		x = (n - x) % n;
		bool ok = false;
		for (int i = 1; i <= n * 2; i++) {
			long long val = 1ll * i * (i + 1) / 2;
			if (val % n == x && i <= p) {
				ok = true;
				break;
			}
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}

