#include <bits/stdc++.h>
using namespace std;

#define MX 505
char s[MX][MX];

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%s", s[i]);
		bool f2 = false, f1 = false;
		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '0') {
					f1 = true;
					for (int ii = -1; ii < 2; ii++)
						for (int jj = -1; jj < 2; jj++) {
							if (!ii && !jj) continue;
							if (i + ii < n && j + jj < m && i + ii >= 0 && j + jj >= 0 && s[i + ii][j + jj] == '0') f2 = true;
						}
				}
				else res++;
			}
		if (f2) printf("%d\n", res);
		else if (f1) printf("%d\n", res - 1);
		else printf("%d\n", res - 2);
	}
	return 0;
}