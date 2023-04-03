#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, k, d, w; scanf("%d%d%d%d", &n, &k, &d, &w);
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int res = 0, cur = -99999999, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > cur) {
				cur = a[i] + w + d;
				if (cnt) res++;
				cnt = 0;
			}
			cnt++;
			if (cnt > k) {
				res++;
				cur = a[i] + w + d;
				cnt -= k;
			}
		}
		printf("%d\n", res + (cnt != 0));
	}
	return 0;
}

