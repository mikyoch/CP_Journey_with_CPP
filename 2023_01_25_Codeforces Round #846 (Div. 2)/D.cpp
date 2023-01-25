#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		int res = 0;
		while (n) {
			printf("- %d\n", 1 << (n - 1));
			fflush(stdout);
			res += (1 << (n - 1));
			int nn;
			scanf("%d", &nn);
			if (nn >= n) {
				int cur = (1 << (n - 1)) * ((1 << (nn - n + 1)) - 1);
				printf("- %d\n", cur);
				fflush(stdout);
				res += cur;
				int t; scanf("%d", &t);
				assert (t == n - 1);
				n = t;
			} else {
				assert (nn == n - 1);
				n = nn;
			}
		}
		printf("! %d\n", res);
		fflush(stdout);
	}
	return 0;
}