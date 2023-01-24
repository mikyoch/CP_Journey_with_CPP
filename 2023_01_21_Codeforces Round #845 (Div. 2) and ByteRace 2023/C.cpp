#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, m; scanf("%d%d", &n, &m);
		vector<int> a(n);
		vector<vector<int>> yak(m + 1);
//		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		vector<int> last(m + 1);
		for (int i = 2; i <= m; i++)
			for (int j = i; j <= m; j += i) yak[j].push_back(i);
		vector<bool> skip(m + 1);
		vector<int> vec;
		for (int i = m; i > 1; i--) {
			if (skip[i]) continue;
			vec.push_back(i);
			for (int k : yak[i]) skip[k] = true;
		}
		printf("%d\n", vec.size());
		vector<bool> vis(m + 1);
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
		}
	}
	return 0;
}
