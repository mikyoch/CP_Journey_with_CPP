#include <bits/stdc++.h>
using namespace std;

#define MX 505
char s[MX][MX];

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> a(n), dp(n, 1);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int res = 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < i + 260 && j < n; j++)
				if ((a[i] ^ j) < (a[j] ^ i)) {
					dp[j] = max(dp[j], dp[i] + 1);
				}
			res = max(res, dp[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}
