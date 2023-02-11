#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<long long> a(n + 1);
	vector<int> id(n + 1);
	long long cur = 0;
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		cur += k;
		a[i] = cur;
	}
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&] (int i, int j) {
		return a[i] < a[j] || a[i] == a[j] && i < j;
	});
	vector<int> l(n + 1);
	for (int i = 0, mn = n; i <= n; i++) {
		mn = min(mn, id[i]);
		l[id[i]] = mn;
	}
	vector<int> b(n + 10);
	auto add = [&] (int u, int x) {
		for (; u <= n + 5; u += u & -u) b[u] += x;
	};
	auto get = [&] (int u) {
		int res = 0;
		for (; u; u -= u & -u) res += b[u];
		return res;
	};
	for (int i = 1; i <= n; i++) {
		int cur = get(l[i]) + i - l[i];
		if (get(i) < cur) add(i, cur - get(i));
	}
	printf("%d\n", get(n));
	return 0;
}

