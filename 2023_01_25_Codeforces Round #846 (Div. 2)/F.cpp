#include <bits/stdc++.h>
using namespace std;

#define MX 300050
int mu[MX];
bool f[MX];
vector<int> yak[MX];

int main() {
	for (int i = 1; i < MX; i++) mu[i] = 1;
	for (int i = 2; i < MX; i++) {
		if (f[i]) continue;
		for (int j = i; j < MX; j += i) {
			f[j] = true;
			if (j / i % i == 0) mu[j] = 0;
			else mu[j] = -mu[j];
		}
	}
	int n; scanf("%d", &n);
	vector<int> pos(MX);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) pos[a[i]] = i + 1;
	long long res = 0;
	for (int i = 1; i < MX; i++) {
		vector<int> vec;
		long long sum = 0;
		for (int j = i; j < MX; j += i)
			if (pos[j]) {
				vec.push_back(pos[j]);
				sum += pos[j];
			}
		for (int j = 0; j < vec.size(); j++) {
			res += (sum - 1ll * vec[j] * (vec.size() - j) - (vec.size() - j - 1)) * mu[i];
			sum -= vec[j];
		}
	}
	printf("%lld\n", res);
	return 0;
}