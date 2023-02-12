#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		int c; scanf("%d", &c);
		while (c--) {
			int k; scanf("%d", &k); k--;
			a[i] |= (1 << k);
		}
	}
	int res = 0;
	for (int mask = 0; mask < (1 << m); mask++) {
		int cur = 0;
		for (int i = 0; i < m; i++) if (mask >> i & 1) cur |= a[i];
		if (cur + 1 == (1 << n)) res++;
	}
	printf("%d\n", res);
	return 0;
}
