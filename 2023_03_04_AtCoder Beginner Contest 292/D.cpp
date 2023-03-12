#include <bits/stdc++.h>
using namespace std;

#define MX 200050
int f[MX], vc[MX], ec[MX];

int find(int x) {
	if (!f[x]) return x;
	return f[x] = find(f[x]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		f[v] = u;
		ec[u] += ec[v];
		vc[u] += vc[v];
	}
	ec[u]++;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) vc[i] = 1;
	while (m--) {
		int u, v; scanf("%d%d", &u, &v);
		merge(u, v);
	}
	bool ok = true;
	for (int i = 1; i <= n; i++)
		if (!f[i] && vc[i] != ec[i]) ok = false;
	puts(ok ? "Yes" : "No");
	return 0;
}

