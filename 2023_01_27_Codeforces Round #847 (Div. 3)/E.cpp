#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		int a = 0, b = 0;
		n <<= 1;
		function<bool(int, int)> func = [&] (int i, int o) {
			if (i > 30) return true;
			int f1 = n >> i & 1;
			int f2 = n >> (i + 1) & 1;
			if (!f1 && !f2) {
				if (o) return false;
				if (func(i + 1, 0)) return true;
				a ^= (1 << i);
				b ^= (1 << i);
				if (func(i + 1, 1)) return true;
				a ^= (1 << i);
				b ^= (1 << i);
			}
			else if (f1 && f2) {
				if (o) return false;
				a ^= (1 << i);
				if (func(i + 1, 0)) return true;
				a ^= (1 << i);
			}
			else if (f1 && !f2) {
				if (!o) return false;
				if (func(i + 1, 0)) return true;
				a ^= (1 << i);
				b ^= (1 << i);
				if (func(i + 1, 1)) return true;
				a ^= (1 << i);
				b ^= (1 << i);
			}
			else if (!f1 && f2) {
				if (!o) return false;
				a ^= (1 << i);
				if (func(i + 1, 1)) return true;
				a ^= (1 << i);
			}
			return false;
		};
		if (func(0, 0)) {
			assert ((a + b) == n && (a ^ b) == n / 2);
			printf("%d %d\n", a, b);
		}
		else puts("-1");
	}
	return 0;
}

