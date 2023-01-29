#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, m; scanf("%d%d", &n, &m);
		vector<pair<int, int>> a(m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
			if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
		}
		sort(a.begin(), a.end());
		set<pair<int, int>> s;
		for (int i = 0; i < m; i++) s.emplace(a[i].second, a[i].first);
		long long res = 0;
		for (int i = 1, cur = 0; i <= n; i++) {
			res += (s.size() ? s.begin()->first : n + 1) - i;
			while (cur < m && a[cur].first == i) {
				s.erase(make_pair(a[cur].second, a[cur].first));
				cur++;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}

