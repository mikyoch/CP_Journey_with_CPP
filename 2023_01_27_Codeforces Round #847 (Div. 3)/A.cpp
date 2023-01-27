#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		char s[100]; scanf("%s", s);
		char pat[] = "314159265358979323846264338327";
		int ans = 0;
		for (int i = 0; i < 30 && s[i] && s[i] == pat[i]; i++) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
