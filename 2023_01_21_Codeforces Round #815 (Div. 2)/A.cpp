#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		long long a, b, c, d; scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if (a * d == 0 && b * c == 0) puts("0");
		else if (a * d == 0 || b * c == 0) puts("1");
		else if (a * d == b * c) puts("0");
		else if (a * d % (b * c) == 0 || b * c % (a * d) == 0) puts("1");
		else puts("2");
	}
	return 0;
}
