#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n; scanf("%d", &n);
		vector<vector<int>> a(n, vector<int>(n - 1));
		vector<int> sum(n + 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - 1; j++) {
				scanf("%d", &a[i][j]);
				sum[a[i][j]] += j;
			}
		vector<int> id(n);
		for (int i = 0; i < n; i++) id[i] = i + 1;
		sort(id.begin(), id.end(), [&] (int i, int j) {
			return sum[i] < sum[j];
		});
		for (int i = 0; i < n; i++) printf("%d%c", id[i], " \n"[i == n - 1]);
	}
	return 0;
}
