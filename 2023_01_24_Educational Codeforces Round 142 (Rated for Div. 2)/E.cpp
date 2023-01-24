#include <bits/stdc++.h>
using namespace std;

#define MX 100050
long long vec[MX];
pair<int, int> yak[MX];

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, m1, m2; scanf("%d%d%d", &n, &m1, &m2);
		int res = 0, rc = 0;
		map<int, int> mp;
		for (int i = 2; i * i <= m1; i++) {
			while (m1 % i == 0) {
				mp[i]++;
				m1 /= i;
			}
		}
		if (m1 != 1) mp[m1]++;
		for (int i = 2; i * i <= m2; i++) {
			while (m2 % i == 0) {
				mp[i]++;
				m2 /= i;
			}
		}
		if (m2 != 1) mp[m2]++;
		int tot = 1;
		int yn = 0;
		for (auto it : mp) {
			it.second++;
			yak[yn++] = it;
			tot *= it.second;
		}
		int vcn = 0;
		for (int mask = 0; mask < tot; mask++) {
			long long cur = 1;
			for (int i = 0, tmp = mask; i < yn; i++) {
				int c = tmp % yak[i].second;
				for (int j = 0; j < c; j++) cur *= yak[i].first;
				tmp /= yak[i].second;
			}
			if (cur <= 1ll * n * n) vec[vcn++] = cur;
		}
		sort(vec, vec + vcn);
		set<long long> s(vec, vec + vcn);
		for (int i = 0; vec[i] <= n; i++) {
			vector<long long> t;
			for (auto v : s) {
				if (v > vec[i] * n) break;
				if (v % vec[i] == 0 && v / vec[i] <= n) rc++, res ^= vec[i], t.push_back(v);
			}
			for (auto v : t) s.erase(v);
		}
		printf("%d %d\n", rc, res);
	}
	return 0;
}
