#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int C = 32000;
bool p[C];
int d[C];
int k;
const int N = (int)2e6 + 55;
int n, m;
int a[N];

void solve() {
	m = 0;
	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		for (int i = 0; i < k; i++) if (x % d[i] == 0) {
			a[m++] = i;
			while(x % d[i] == 0) x /= d[i];
		}
		if (x > 1) a[m++] = x;
	}
	sort(a, a + m);
	for (int i = 1; i < m; i++) {
		if (a[i] == a[i - 1]) {
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	for (int i = 2; i < C; i++)
		p[i] = 1;
	for (int i = 2; i < C; i++) if (p[i]) {
		d[k++] = i;
		for (int j = 2 * i; j < C; j += i)
			p[j] = 0;
	}
	printf("%d\n", k);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}

