#include <bits/stdc++.h>
using namespace std;

#define MX 500050
char s[MX];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	int mn = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		int cnt[2] = {0};
		for (int j = 0; s[j]; j++) cnt[s[j] - '0']++;
		int s1 = 0;
		for (int j = 0; s[j]; j++) {
			if (s[j] == '1' && s[j + 1] == '1') s1++, j++;
		}
		mn += cnt[1] - min(s1, m / 4);
		int s0 = 0;
		for (int j = 0; s[j]; j++) {
			if (s[j + 1] && (s[j] != '1' || s[j + 1] != '1')) s0++, j++;
		}
		int t = m / 4 * 3 - (cnt[0] - min(s0, m / 4));
		mx += t;
	}
	printf("%d %d\n", mn, mx);
	return 0;
}
