#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> a(n);
		map<int, int> mp;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]), mp[a[i]]++;
		int prv = -1, ans = 0;
		for (auto it : mp) {
			if (prv + 1 < it.first) {
				ans += it.second;
			} else {
				assert (prv + 1 == it.first);
				if (mp[prv] < it.second) ans += it.second - mp[prv];
			}
			prv = it.first;
		}
		printf("%d\n", ans);
	}
	return 0;
}
