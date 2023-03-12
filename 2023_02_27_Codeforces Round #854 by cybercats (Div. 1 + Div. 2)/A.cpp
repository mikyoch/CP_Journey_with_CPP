#include <bits/stdc++.h>
using namespace std;

#define MX 1200050
using ll = long long;
const ll INF = LLONG_MAX >> 4;
ll mn[MX], add[MX];

inline int renew(int u, ll x) {
	add[u] += x;
	mn[u] += x;
}

inline int down(int u) {
	renew(u + u, add[u]);
	renew(u + u + 1, add[u]);
	add[u] = 0;
}

void up(int u) {
	mn[u] = min(mn[u + u], mn[u + u + 1]);
}

void build(int u, int l, int r) {
	add[u] = 0;
	if (l == r) {
		mn[u] = (l == 1 ? 0 : INF);
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
	if (ed < l || st > r) return INF;
	if (l >= st && r <= ed) {
		return mn[u];
	}
	int m = l + r >> 1;
	ll res = LLONG_MAX;
	down(u);
	if (st <= m) res = min(res, query(u + u, l, m, st, ed));
	if (m + 1 <= ed) res = min(res, query(u + u + 1, m + 1, r, st, ed));
	return res;
}
 
int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, k; scanf("%d%d", &n, &k);
		vector<int> a(n + 1), hot(k + 1), cold(k + 1);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= k; i++) scanf("%d", &hot[i]);
		for (int i = 1; i <= k; i++) scanf("%d", &cold[i]);
		build(1, 1, k + 1);
		for (int i = 1; i <= n; i++) {
			ll mn = query(1, 1, k + 1, 1, k + 1);
			ll cur = query(1, 1, k + 1, a[i] + 1, a[i] + 1);
			ll v = min(cur + cold[a[i]], mn + hot[a[i]]);
			update(1, 1, k + 1, 1, k + 1, a[i] == a[i - 1] ? cold[a[i]] : hot[a[i]]);
			ll org = query(1, 1, k + 1, a[i - 1] + 1, a[i - 1] + 1);
			update(1, 1, k + 1, a[i - 1] + 1, a[i - 1] + 1, v - org);
		}
		printf("%lld\n", query(1, 1, k + 1, 1, k + 1));
	}
	return 0;
}
