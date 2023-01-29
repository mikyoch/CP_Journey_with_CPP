#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> a(n);
		int mn = INT_MAX, mx = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			mn = min(mn, a[i]);
			mx = max(mx, a[i]);
		}
		int mnc = 0, mxc = 0;
		for (int i = 0; i < n; i++) {
			if (mn == a[i]) mnc++;
			if (mx == a[i]) mxc++;
		}
		if (mn == mx) printf("%lld\n", 1ll * n * (n - 1));
		else printf("%lld\n", 2ll * mnc * mxc);
	}
	return 0;
}

