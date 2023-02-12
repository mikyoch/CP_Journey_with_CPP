#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<int> a(m);
	for (int i = 0; i < m; i++) scanf("%d", &a[i]);
	vector<int> ans;
	for (int i = 1, j = 0; i <= n; i++) {
		if (j >= m || a[j] != i) {
			ans.push_back(i);
			for (int k = i - 1, l = j - 1; l >= 0 && k && a[l] == k; k--, l--) ans.push_back(a[l]);
		} else j++;
	}
	for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], " \n"[i == n - 1]);
	return 0;
}
