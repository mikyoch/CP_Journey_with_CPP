#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, Q; scanf("%d%d", &n, &Q);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	vector<int> L(Q), R(Q), id(Q);
	vector<long long> ans(Q);
	for (int i = 0; i < Q; i++) scanf("%d%d", &L[i], &R[i]), id[i] = i;
	int SEG = 300;
	sort(id.begin(), id.end(), [&] (int i, int j) {
		if (L[i] / SEG != L[j] / SEG) return L[i] < L[j];
		return R[i] > R[j];
	});
	const int MX = 200050;
	vector<int> cnt(MX);
	long long res = 0;
	for (int i = 1; i <= n; i++) cnt[a[i]]++;
	for (int i = 1; i < MX; i++) res += 1ll * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
	int st = 1, ed = n;
	for (int i = 0; i < Q; i++) {
		int l = L[id[i]], r = R[id[i]];
		while (st < l) {
			cnt[a[st]]--;
			res -= 1ll * cnt[a[st]] * (cnt[a[st]] - 1) / 2;
			st++;
		}
		while (st > l) {
			res += 1ll * cnt[a[st-1]] * (cnt[a[st-1]] - 1) / 2;
			cnt[a[st-1]]++;
			st--;
		}
		while (ed < r) {
			res += 1ll * cnt[a[ed+1]] * (cnt[a[ed+1]] - 1) / 2;
			cnt[a[ed+1]]++;
			ed++;
		}
		while (ed > r) {
			cnt[a[ed]]--;
			res -= 1ll * cnt[a[ed]] * (cnt[a[ed]] - 1) / 2;
			ed--;
		}
		ans[id[i]] = res;
	}
	for (int i = 0; i < Q; i++) printf("%lld\n", ans[i]);
	return 0;
}
