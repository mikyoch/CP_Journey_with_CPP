#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, Q; scanf("%d%d", &n, &Q);
	int cur = 1;
	queue<int> q;
	vector<bool> vis(n + 1);
	while (Q--) {
		int t; scanf("%d", &t);
		if (t == 1) q.push(cur++);
		if (t == 2) {
			int x; scanf("%d", &x);
			vis[x] = true;
		}
		if (t == 3) {
			while (vis[q.front()]) q.pop();
			printf("%d\n", q.front());
		}
	}
	return 0;
}

