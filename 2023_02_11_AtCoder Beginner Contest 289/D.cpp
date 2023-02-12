#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	vector<bool> trap(100050);
	vector<bool> dp(100050);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int k; scanf("%d", &k);
		trap[k] = true;
	}
	int x; scanf("%d", &x);
	dp[0] = true;
	for (int i = 0; i < x; i++) {
		if (trap[i] || !dp[i]) continue;
		for (int j = 0; j < n; j++) dp[i + a[j]] = true;
	}
	puts(dp[x] ? "Yes" : "No");
	return 0;
}
