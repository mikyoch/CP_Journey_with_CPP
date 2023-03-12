#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		int d = max(max(a, b), c);
		a = d - a;
		b = d - b;
		c = d - c;
		if (a % 2 || b % 2 || c % 2 || (a + b + c) % 6) puts("-1");
		else {
			if (a > b) swap(a, b);
			if (a > c) swap(a, c);
			if (b > c) swap(b, c);
			printf("%d\n", (b + min(b * 2, c)) / 6 + (c - min(b * 2, c)) / 3);
		}
	}
	return 0;
}
