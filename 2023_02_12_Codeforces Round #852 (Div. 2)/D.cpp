#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> p(n + 1), q(n + 1);
	vector<int> pp(n + 1), qp(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &q[i]);
		pp[p[i]] = i;
		qp[q[i]] = i;
	}
	int l = n - 1, r = 0;
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		int a = pp[i], b = qp[i];
		if (a > b) swap(a, b);
		if (l > r) { // i == 1
			res += 1ll * a * (a - 1) / 2;
			res += 1ll * (n - b) * (n - b + 1) / 2;
			res += 1ll * (b - a - 1) * (b - a) / 2;
		} else {
			if (a < l && r < b) {
				res += 1ll * (l - a) * (r - b);
			} else if (b < l) {
				res += 1ll * (l - b) * (n - r + 1);
			} else if (r < a) {
				res += 1ll * l * (a - r);
			}
		}
		l = min(l, a);
		r = max(r, b);
	}
	printf("%lld\n", res + 1);
	return 0;
}
