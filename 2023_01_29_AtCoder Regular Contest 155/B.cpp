#include <bits/stdc++.h>
using namespace std;

int main() {
	long long Q; scanf("%lld", &Q);
	set<long long> s, ab, ba;
	long long a, b; scanf("%lld%lld", &a, &b);
	s.insert(a + b);
	if (a >= b)s.insert(a - b);
	if (b >= a) ba.insert(b - a);
	while (Q--) {
		long long t; scanf("%lld%lld%lld", &t, &a, &b);
		if (t == 1) {
			s.insert(a + b);
			if (a >= b)s.insert(a - b);
			if (b >= a) ba.insert(b - a);
		} else {
			long long res = LLONG_MAX;
			auto it = s.lower_bound(a);
			if (it != s.end()) res = min(res, *it - b);
			it = s.upper_bound(b);
			if (it != s.begin()) {
				it--;
				res = min(res, a - *it);
			}
//			it = ab.lower_bound(a);
//			if (it != ab.end()) res = min(res, *it - b);
//			it = ab.upper_bound(b);
//			if (it != ab.begin()) {
//				it--;
//				res = min(res, a - *it);
//			}
//			it = ba.begin();
//			res = min(res, *it + a);
			printf("%lld\n", max(0ll, res));
		}
	}
	return 0;
}

