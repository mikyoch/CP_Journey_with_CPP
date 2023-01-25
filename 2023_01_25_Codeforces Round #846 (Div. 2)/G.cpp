#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int res = 0;
	using ull = unsigned long long;
	for (int i = 1; i <= n; i++) {
		ull cur = 0;
		ull base = 1;
		for (int j = 0; j < i; j++) base *= 29;
		map<ull, int> mp;
		for (int j = 0; j < n; j++) {
			cur = cur * 29 + s[j] - 'a' + 1;
			if (j >= i) {
				cur -= (s[j - i] - 'a' + 1) * base;
			}
			if (j >= i - 1) mp[cur]++;
		}
		for (auto it : mp) {
			if (it.second % i == 0) res += it.second;
		}
	}
	cout << res << endl;
	return 0;
}
