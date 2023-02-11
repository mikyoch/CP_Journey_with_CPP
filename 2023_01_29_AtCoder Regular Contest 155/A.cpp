#include <bits/stdc++.h>
using namespace std;

#define MX 200050
char s[MX];

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n;
		long long k; scanf("%d%lld", &n, &k);
		scanf("%s", s);
		bool ok = false;
		for (int t = 1; t * t <= n; t++) {
			auto func = [&] (int t) {
				for (int i = 0; i < n / t; i++) {
					for (int j = 0; j < t; j++) {
						if (s[i * t + j] != s[i % 2 ? t - j - 1 : j]) return false;
					}
				}
				bool ok = true;
				for (int j = 0; j < t; j++)
					if (s[j] != s[t - j - 1]) ok = false;
				if (ok) return k % t == 0;
				return k % t == 0 && k / t % 2 && n / t % 2;
			};
			if (n % t == 0) {
				if (func(t) || func(n / t)) {
					ok = true;
					break;
				}
			}
			if (ok) break;
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}
