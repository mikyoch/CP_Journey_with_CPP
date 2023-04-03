#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		string s; cin >> s;
		int n = s.size();
		vector<vector<long long>> dp(n + 1, vector<long long>(4, LLONG_MAX >> 1));
		for (int i = 0; i < n; i++) s[i] -= '0';
		dp[0][s[0]] = 0;
		auto mini = [&] (long long &a, long long b) {
			if (a > b) a = b;
		};
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++) {
					if (j > 1 && k < 2) continue;
					int t1 = k / 2;
					int t2 = k % 2;
					if (j % 2 == k / 2) {
						if (i == n || s[i] == t2) mini(dp[i][k], dp[i - 1][j]);
						continue;
					}
					if (i < n && s[i] == t1 && t1 != t2)
					  	mini(dp[i][k], dp[i - 1][j] + 1000000000000ll);
					else if (i == n || s[i] == t2)
						mini(dp[i][k], dp[i - 1][j] + 1000000000001ll);
				}
		}
		long long ans = LLONG_MAX;
		for (int i = 0; i < 4; i++) ans = min(ans, dp[n][i]);
		printf("%lld\n", ans);
	}
	return 0;
}
