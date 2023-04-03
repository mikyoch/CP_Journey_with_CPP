#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> a(n), ans(n, 2), dp(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = n - 1; i >= 0; i--)
			if (a[i] == n - 1 - i) {
				dp[i] = 1;
			}
		for (int i = n - 1; i >= 0; i--) {
			int cur = i + a[i] + 1;
			if (cur <= n - 1 && dp[cur]) dp[i] = dp[cur] + 1;
		}
		for (int i = n - 2; i >= 0; i--) {
			if (dp[i + 1]) {
				if (dp[i + 1] == a[i]) ans[i] = 0;
				else ans[i] = 1;
			}
		}
		vector<int> last(n + 1);
		for (int i = n - 1; i >= 0; i--) {
			if (!last[dp[i]]) last[dp[i]] = i;
		}
		for (int i = n - 2; i >= 0; i--) {
			if (ans[i] == 2) {
			}
		}
		for (int i = 0; i < n - 1; i++) printf("%d%c", ans[i], " \n"[i == n - 2]);
	}
	return 0;
}

