#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<long long> a(100, 1);
		for (int i = 2; i * i <= n; i++) {
			for (int j = 1; n % i == 0; j++) {
				n /= i;
				a[j] *= i;
			}
		}
		if (n != 1) a[1] *= n;
		long long res = 0;
		for (int i = 0; i < 100; i++)
			if (a[i] > 1) res += a[i];
		printf("%lld\n", res);
	}
	return 0;
}

