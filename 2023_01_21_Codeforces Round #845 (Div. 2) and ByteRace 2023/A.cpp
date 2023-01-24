#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int res = 0;
		for (int i = 1; i < n; i++)
			if (a[i - 1] % 2 == a[i] % 2) res++;
		printf("%d\n", res);
	}
	return 0;
}
