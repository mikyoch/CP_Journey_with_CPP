#include <bits/stdc++.h>
using namespace std;

int f[200050];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i) f[j]++;
	long long res = 0;
	for (int i = 1; i <= n; i++) res += 1ll * f[i] * f[n - i];
	printf("%lld\n", res);
	return 0;
}
