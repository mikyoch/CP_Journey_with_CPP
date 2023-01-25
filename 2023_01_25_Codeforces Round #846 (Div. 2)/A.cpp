#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> a[2];
		for (int i = 1; i <= n; i++) {
			int k; scanf("%d", &k);
			a[k % 2].push_back(i);
		}
		if (a[1].size() == 0) puts("NO");
		else {
			if (a[1].size() < 3 && a[0].size() < 2) puts("NO");
			else {
				puts("YES");
				if (a[0].size() > 1) printf("%d %d %d\n", a[1][0], a[0][0], a[0][1]);
				else printf("%d %d %d\n", a[1][0], a[1][1], a[1][2]);
			}
		}
	}
	return 0;
}