#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> a(n), vec;
		long long sum = 0;
		vector<long long> L(n), R(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
		for (int i = 0; i < n; i++) {
			while (vec.size() && a[vec.back()] - vec.back() > a[i] - i) vec.pop_back();
			if (vec.empty()) L[i] = 1ll * (a[i] + max(1, a[i] - i)) * (a[i] - max(1, a[i] - i) + 1) / 2;
			else L[i] = L[vec.back()] + 1ll * (a[i] + a[i] + vec.back() - i + 1) * (i - vec.back()) / 2;
			vec.push_back(i);
		}
		vec.clear();
		reverse(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			while (vec.size() && a[vec.back()] - vec.back() > a[i] - i) vec.pop_back();
			if (vec.empty()) R[i] = 1ll * (a[i] + max(1, a[i] - i)) * (a[i] - max(1, a[i] - i) + 1) / 2;
			else R[i] = R[vec.back()] + 1ll * (a[i] + a[i] + vec.back() - i + 1) * (i - vec.back()) / 2;
			vec.push_back(i);
		}
		long long ans = sum;
		for (int i = 0; i < n; i++) ans = min(ans, sum - L[i] - R[n - i - 1] + a[n - i - 1] + a[n - i - 1]);
		printf("%lld\n", ans);
	}
	return 0;
}
