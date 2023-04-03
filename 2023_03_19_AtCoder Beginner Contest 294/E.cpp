#include <bits/stdc++.h>
using namespace std;

int main() {
	int L, N1, N2; scanf("%d%d%d", &L, &N1, &N2);
	vector<long long> v1(N1), l1(N1);
	vector<long long> v2(N2), l2(N2);
	for (int i = 0; i < N1; i++) scanf("%lld%lld", &v1[i], &l1[i]);
	for (int i = 0; i < N2; i++) scanf("%lld%lld", &v2[i], &l2[i]);
	long long i1 = 0, i2 = 0, c1 = l1[0], c2 = l2[0];
	long long res = 0;
	while (i1 < N1 && i2 < N2) {
		long long mc = min(c1, c2);
		if (v1[i1] == v2[i2]) res += mc;
		c1 -= mc;
		c2 -= mc;
		if (!c1) c1 = l1[++i1];
		if (!c2) c2 = l2[++i2];
	}
	printf("%lld\n", res);
	return 0;
}
