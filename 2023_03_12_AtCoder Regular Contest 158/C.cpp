#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	long long res = 0;
	for (int i = 0; i < n; i++)
		for (auto c : a[i]) res += (c - '0') * n * 2;
	for (int i = 0; i < 16; i++) {
		vector<long long> vec;
		for (int j = 0; j < n; j++) {
			long long cur = 0;
			for (int k = i; k >= 0; k--)
				if (k < a[j].size()) cur = cur * 10 + a[j][a[j].size() - 1 - k] - '0';
			vec.push_back(cur);
		}
		long long base = 1;
		for (int j = 0; j <= i; j++) base *= 10;
		sort(vec.begin(), vec.end());
		for (int j = 0; j < n; j++) res -= 9 * (vec.end() - lower_bound(vec.begin(), vec.end(), base - vec[j]));
	}
	printf("%lld\n", res);
	return 0;
}
