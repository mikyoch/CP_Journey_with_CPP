#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, k; scanf("%d%d", &n, &k);
		vector<pair<int, int>> seg(n);
		vector<int> cnt(1000);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &seg[i].first, &seg[i].second);
			if (seg[i].first <= k && seg[i].second >= k)
			for (int j = seg[i].first; j <= seg[i].second; j++) cnt[j]++;
		}
		bool ok = cnt[k];
		for (int i = 0; i < n; i++) {
			if (k >= seg[i].first && k <= seg[i].second) {
				for (int j = seg[i].first; j <= seg[i].second; j++) {
					if (j != k && cnt[j] >= cnt[k]) ok = false;
				}
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}

