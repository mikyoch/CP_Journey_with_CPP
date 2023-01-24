#include <bits/stdc++.h>
using namespace std;


int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		vector<vector<int>> g(n * 30, vector<int>(2));
		vector<vector<int>> dp(n);
		for (int i = 0; i < n; i++) {
			int p = a[i] ^ i;
			for (int j = 30; j >= 0; j--) {
				if ((!i >> j & 1)) dp[i] = max(dp[i], dp[g[cur][1]]);
			}
		}
	}
	return 0;
}
