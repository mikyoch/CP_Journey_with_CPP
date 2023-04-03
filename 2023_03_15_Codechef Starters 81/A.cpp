#include <bits/stdc++.h>
using namespace std;

char s[1000050];

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
	    int n; scanf("%d", &n);
	    scanf("%s", s);
	    int r[2] = {0};
	    int res = 0;
	    for (int i = 0; i < n; i++) {
	    	s[i] -= '0';
	    	res += r[s[i]] + 1;
	    	r[0] *= 2;
	    	r[1] *= 2;
	    	r[s[i]] += 1;
	    }
	    printf("%d\n", res);
	}
	return 0;
}

