#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		if (n & 1) puts("-1");
		else printf("%d %d\n", 1, n / 2);
	}
	return 0;
}

