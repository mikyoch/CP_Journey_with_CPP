#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, s, r; scanf("%d%d%d", &n, &s, &r);
		vector<int> a(n);
		a[0] = s - r;
		while (r) {
			for (int i = 1; i < n && r; i++) {
				a[i]++;
				r--;
			}
		}
		for (int i = 0; i < n; i++) printf("%d%c", a[i], " \n"[i == n - 1]);
	}
	return 0;
}
