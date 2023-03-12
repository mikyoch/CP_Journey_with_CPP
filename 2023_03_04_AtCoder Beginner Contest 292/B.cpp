#include <bits/stdc++.h>
using namespace std;

int cnt[200050];

int main() {
	int n, q; scanf("%d%d", &n, &q);
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		if (x == 1) cnt[y]++;
		if (x == 2) cnt[y] += 2;
		if (x == 3) puts(cnt[y] >= 2 ? "Yes" : "No");
	}
	return 0;
}
