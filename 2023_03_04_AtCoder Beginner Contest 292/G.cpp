#include <bits/stdc++.h>
using namespace std;

char s[100][100];
int dp[100][100][11][2];
const int mod = 998244353;

void add(int& a, int b) {
	a += b;
	if (a > mod) a -= mod;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 10; k++) {
				if (!j) {
					if (i) {
						dp[i][j][k][0] = dp[i - 1][j][k][0];
						dp[i][j][k][1] = dp[i - 1][j][k][1];
					}
					else {
						dp[i][j][k][0] = 1;
						dp[i][j][k][1] = 1;
					}
				} else {
					add(dp[i][j][k][0], dp[i][j - 1][k][0]);
					for (int h = 0; h < k; h++)
						add(dp[i][j][k][1], dp[i][j - 1][k][0]);
				}
			}
	return 0;
}

