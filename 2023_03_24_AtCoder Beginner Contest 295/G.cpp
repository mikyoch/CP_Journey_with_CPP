#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % p) {
		if (n & 1) {
			ret = ret * 1LL * a % p;
		}
	}
	return ret;
}

int C[2200][2200];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n + 1);
	int zeros = 0;
	vector<int> cnt(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]) {
			cnt[a[i]]++;
		} else {
			zeros++;
		}
	}
	for (int i = 0; i <= zeros; i++) {
		for (int j = 0; j <= i; j++) {
			C[i][j] = j == 0 ? 1 : (C[i - 1][j] + C[i - 1][j - 1]) % P;
		}
	}
	for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (cnt[i - 1] >= k) {
			break;
		}
		for (int j = 0; j <= zeros; j++) {
			if (j + cnt[i - 1] < k) {
				ans = (ans + modExp(i - 1, j, P) * 1LL * modExp(m - i + 1, zeros - j, P) % P * C[zeros][j]) % P;
			}
		}
	}
	ans = ans * 1LL * modExp(m, P - 1 - zeros, P) % P;
	return cout << ans << endl, 0;
}

