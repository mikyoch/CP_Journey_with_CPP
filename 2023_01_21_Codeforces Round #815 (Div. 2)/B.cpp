#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		printf("%d\n", a[n - 1] + a[n - 2] - a[0] - a[1]);
	}
	return 0;
}