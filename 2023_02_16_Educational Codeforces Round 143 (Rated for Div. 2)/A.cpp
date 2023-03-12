#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		int n, m; scanf("%d%d", &n, &m);
		char a[100], b[100]; scanf("%s%s", a, b);
		bool good = false;
		for (int i = 0; i <= n; i++) {
			bool ok = true;
			string A, B;
			for (int j = 0; j < n - i; j++) A += a[j];
			for (int j = 0; j < m; j++) B += b[j];
			for (int j = 0; j < i; j++) B += a[n - j - 1];
			for (int j = 1; j < A.size(); j++)
				if (A[j] == A[j - 1]) ok = false;
			for (int j = 1; j < B.size(); j++)
				if (B[j] == B[j - 1]) ok = false;
			if (ok) good = true;
		}
		for (int i = 0; i <= m; i++) {
			bool ok = true;
			string A, B;
			for (int j = 0; j < n; j++) A += a[j];
			for (int j = 0; j < m - i; j++) B += b[j];
			for (int j = 0; j < i; j++) A += b[m - j - 1];
			for (int j = 1; j < A.size(); j++)
				if (A[j] == A[j - 1]) ok = false;
			for (int j = 1; j < B.size(); j++)
				if (B[j] == B[j - 1]) ok = false;
			if (ok) good = true;
		}
		puts(good ? "YES" : "NO");
	}
	return 0;
}

