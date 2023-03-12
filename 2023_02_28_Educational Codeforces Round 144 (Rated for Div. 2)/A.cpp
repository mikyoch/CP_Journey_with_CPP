#include <bits/stdc++.h>
using namespace std;

#define MX 1200050
using ll = long long;
ll mx[MX], add[MX], b[MX >> 2];

inline void renew(int u, ll x) {
	add[u] += x;
	mx[u] += x;
}

inline void down(int u) {
	renew(u + u, add[u]);
	renew(u + u + 1, add[u]);
	add[u] = 0;
}

void up(int u) {
	mx[u] = max(mx[u + u], mx[u + u + 1]);
}

void build(int u, int l, int r) {
	add[u] = 0;
	if (l == r) {
		mx[u] = b[l];
		return;
	}
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(u + u + 1, mid + 1, r);
	up(u);
}

void update(int u, int l, int r, int st, int ed, ll x) {
	if (ed < l || st > r) return;
	if (l >= st && r <= ed) {
		renew(u, x);
		return;
	}
	int m = l + r >> 1;
	down(u);
	if (st <= m) update(u + u, l, m, st, ed, x);
	if (m + 1 <= ed) update(u + u + 1, m + 1, r, st, ed, x);
	up(u);
}
 
ll query(int u, int l, int r, int st, int ed) {
	if (ed < l || st > r || st > ed) return LLONG_MIN;
	if (l >= st && r <= ed) {
		return mx[u];
	}
	int m = l + r >> 1;
	ll res = LLONG_MIN;
	down(u);
	if (st <= m) res = max(res, query(u + u, l, m, st, ed));
	if (m + 1 <= ed) res = max(res, query(u + u + 1, m + 1, r, st, ed));
	return res;
}
 
int main() {
	int tc; scanf("%d", &tc);
	for (int tt = 0; tt < tc; tt++) {
		int n, k, x; scanf("%d%d%d", &n, &k, &x);
		vector<ll> a(n + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		ll ans = 0;
		for (int c = 1; c <= k; c++)
			for (int i = 1; i <= n; i++) {
				ll sum = 0;
				for (int j = 0; j < c && i + j <= n; j++) sum += a[i + j] + x;
				ans = max(ans, sum);
			}
		for (int i = 1; i <= n; i++) a[i] -= x;
		for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
		build(1, 1, n);
		for (int i = 1; i <= n - k + 1; i++) {
			ll cur = query(1, 1, n, i + k - 1, n) + 2ll * k * x;
			ans = max(ans, cur);
			update(1, 1, n, i, n, -a[i]);
		}
		if (x < 0) {
		for (int t = 0; t <= k; t++) {
			for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
			build(1, 1, n);
			for (int i = 1; i <= n - k + t + 1; i++) {
				ll cur = query(1, 1, n, i + k - t - 1, n - (t - min(i - 1, t))) + 2ll * (k - t) * x;
				ans = max(ans, cur);
				update(1, 1, n, i, n, -a[i]);
			}
		}}
		printf("%lld\n", ans);
	}
	return 0;
}
