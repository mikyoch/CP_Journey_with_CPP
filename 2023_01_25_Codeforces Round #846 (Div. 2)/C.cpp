#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, m; scanf("%d%d", &n, &m);
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int k; scanf("%d", &k);
			mp[k]++;
		}
		vector<int> c(m);
		for (int i = 0; i < m; i++) scanf("%d", &c[i]);
		sort(c.begin(), c.end(), greater<int>());
		priority_queue<int> q;
		for (auto it : mp) q.push(it.second);
		long long res = 0;
		for (int i = 0; i < m; i++) {
			if (q.size()) {
				int t = q.top(); q.pop();
				res += min(t, c[i]);
				if (t > c[i]) q.push(t - c[i]);
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}