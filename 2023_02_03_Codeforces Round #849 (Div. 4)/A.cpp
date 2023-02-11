#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, c; scanf("%d%d", &n, &c);
		int C = c;
		vector<int> a(n + 1), b(n + 1);
		vector<pair<int, int>> vec;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i] + n + 1 - i;
			a[i] += i;
			if (a[i] <= b[i]) vec.emplace_back(a[i], 1);
			else vec.emplace_back(b[i], 2);
		}
		sort(vec.begin(), vec.end());
		bool flag = false;
		int res = 0;
		for (int i = 0; i < n; i++) {
			c -= vec[i].first;
			if (c < 0) {
				c += vec[i].first;
				break;
			}
			else {
				res++;
				if (vec[i].second == 1) flag = true;
			}
		}
		if (flag || !res) printf("%d\n", res);
		else {
			printf("%d\n", res);
			int last = (res == n ? INT_MAX / 2 : vec[res].first);
			bool bad = true;
			for (int i = 1; i <= n; i++) {
				if (min(a[i], b[i]) <= vec[res - 1].first) {
					if (c >= a[i] - min(a[i], b[i])) {
						bad = false;
						break;
					}
				} else {
					long long tmp = c + vec[res - 1].first;
					if (tmp >= a[i]) {
						bad = false;
						break;
					}
				}
			}
			printf("%d\n", res - bad);
		}
	}
	return 0;
}
