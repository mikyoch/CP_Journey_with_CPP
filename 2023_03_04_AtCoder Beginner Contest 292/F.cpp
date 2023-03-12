#include <bits/stdc++.h>
using namespace std;

#define MX 1000050
bool f[MX];

int main() {
	f[1] = true;
	for (int i = 2; i < MX; i++) {
		if (f[i]) continue;
		for (int j = i + i; j < MX; j += i) f[j] = true;
	}
	int n; scanf("%d", &n);
	map<int, int> mp;
	for (int i = 0; i < 2 * n; i++) {
		int k; scanf("%d", &k);
		mp[k]++;
	}
	const int mod = 998244353;
	int N = 2 * n + 200;
	vector<int> fac(N), ifac(N), q(N);
	fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
	q[0] = q[1] = 1;
	for (int i = 2; i < N; i++) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		q[i] = 1ll * q[mod % i] * (mod - mod / i) % mod;
		ifac[i] = 1ll * ifac[i - 1] * q[i] % mod;
	}
	vector<int> cnt;
	cnt.push_back(0);
	int res = fac[n];
	for (auto it : mp) {
		if (!f[it.first])
			cnt.push_back(it.second);
		else res = 1ll * res * ifac[it.second] % mod;
	}
	if (cnt.size() - 1 < n) {
		puts("0");
		return 0;
	}
	int tot = 0;
	vector<int> dp(N);
	dp[0] = 1;
	for (int i = 1; i < cnt.size(); i++) {
		int c = cnt[i];
		vector<int> pd(N);
		for (int j = 0; j <= i; j++) {
			pd[j] = (pd[j] + 1ll * dp[j] * ifac[c]) % mod;
			if (j) pd[j] = (pd[j] + 1ll * dp[j - 1] * ifac[c - 1]) % mod;
		}
		tot += c;
		dp = pd;
	}
	printf("%d\n", 1ll * dp[n] * res % mod);
    return 0;
}

