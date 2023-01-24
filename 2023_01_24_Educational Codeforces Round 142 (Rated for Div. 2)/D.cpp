#include <bits/stdc++.h>
using namespace std;

#define MX 500050
int trie[MX][11];
int cnt = 1;

int newNode() {
    int x = ++cnt;
    for (int i = 0; i < 11; i++) trie[x][i] = 0;
    return x;
}
 
void add(vector<int> vec) {
    int p = 1;
    for (int d : vec) {
        if (!trie[p][d]) trie[p][d] = newNode();
        p = trie[p][d];
    }
}

int query(vector<int> vec) {
	int p = 1, c = 0;
	for (int d : vec) {
		if (!trie[p][d]) return c;
		p = trie[p][d]; c++;
	}
	return c;
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, m; scanf("%d%d", &n, &m);
		vector<vector<int>> a(n, vector<int>(m + 1));
		cnt = 0;
		newNode();
		for (int i = 0; i < n; i++) {
			vector<int> vec(m + 1);
			for (int j = 1; j <= m; j++) {
				scanf("%d", &a[i][j]);
				vec[a[i][j]] = j;
			}
			add(vec);
		}
		for (int i = 0; i < n; i++) printf("%d%c", query(a[i]) - 1, " \n"[i == n - 1]);
	}
	return 0;
}
