#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, k; scanf("%d%d", &n, &k);
		vector<int> a(n);
		set<pair<int, int> > event;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			int d = k;
			for (int j = 1; j * j <= a[i]; j++) {
				if (j <= k) event.emplace(a[i] / j, i);
				if (a[i] / (j + 1) + 1 <= k) event.emplace(j, i);
			}
			if (a[i] < k) event.emplace(0, i);
		}
		multiset<int> ms;
		vector<int> prev(n, -1);
		int res = INT_MAX;
		for (auto e : event) {
			if (prev[e.second] >= 0) {
				auto it = ms.find(prev[e.second]);
				assert (it != ms.end());
				ms.erase(it);
			}
			ms.insert(e.first);
			if (ms.size() == n) {
				res = min(res, e.first - *ms.begin());
			}
			prev[e.second] = e.first;
		}
		printf("%d\n", res);
	}
	return 0;
}
