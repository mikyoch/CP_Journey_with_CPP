#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	map<int, int> mp;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	vector<int> c = a;
	for (int i = 0; i < m; i++) c.push_back(b[i]);
	sort(c.begin(), c.end());
	for (int i = 0; i < n + m; i++) mp[c[i]] = i + 1;
	for (int i = 0; i < n; i++) printf("%d%c", mp[a[i]], " \n"[i == n - 1]);
	for (int i = 0; i < m; i++) printf("%d%c", mp[b[i]], " \n"[i == m - 1]);
	return 0;
}

