#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
long long max_factor, n;

inline long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

inline long long quick_pow(long long x, long long p, long long mod) {  // ???
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (__int128)ans * x % mod;
    x = (__int128)x * x % mod;
    p >>= 1;
  }
  return ans;
}

inline bool Miller_Rabin(long long p) {  // ????
  if (p < 2) return 0;
  if (p == 2) return 1;
  if (p == 3) return 1;
  long long d = p - 1, r = 0;
  while (!(d & 1)) ++r, d >>= 1;  // ?d?????
  for (long long k = 0; k < 10; ++k) {
    long long a = rand() % (p - 2) + 2;
    long long x = quick_pow(a, d, p);
    if (x == 1 || x == p - 1) continue;
    for (int i = 0; i < r - 1; ++i) {
      x = (__int128)x * x % p;
      if (x == p - 1) break;
    }
    if (x != p - 1) return 0;
  }
  return 1;
}

inline long long Pollard_Rho(long long x) {
  long long s = 0, t = 0;
  long long c = (long long)rand() % (x - 1) + 1;
  int step = 0, goal = 1;
  long long val = 1;
  for (goal = 1;; goal *= 2, s = t, val = 1) {  // ????
    for (step = 1; step <= goal; ++step) {
      t = ((__int128)t * t + c) % x;
      val = (__int128)val * abs(t - s) % x;
      if ((step % 127) == 0) {
        long long d = gcd(val, x);
        if (d > 1) return d;
      }
    }
    long long d = gcd(val, x);
    if (d > 1) return d;
  }
}

inline void fac(long long x) {
  if (x <= max_factor || x < 2) return;
  if (Miller_Rabin(x)) {              // ??x???
    max_factor = max(max_factor, x);  // ????
    return;
  }
  long long p = x;
  while (p >= x) p = Pollard_Rho(x);  // ?????
  while ((x % p) == 0) x /= p;
  fac(x), fac(p);  // ??????x?p
}

inline vector<long long> prime_sieve(long long n) {
	vector<long long> res;
	while (n > 1) {
		max_factor = 0;
		fac(n);
		res.push_back(max_factor);
		n /= max_factor;
	}
	return res;
}

map<long long, int> save;

inline int get(long long n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (save[n]) return save[n];
	auto ps = prime_sieve(n);
	map<long long, int> mp;
	for (auto v : ps) mp[v]++;
	vector<pair<long long, int>> vec;
	for (auto it : mp) {
		vec.push_back(it);
	}
	int ans = 0;
	function<void(long long, int)> dfs = [&] (long long val, int pos) {
		if (pos == vec.size()) {
			if (val != 1) {
				bool ok = true;
				long long tmp = n;
				while (tmp) {
					if (tmp % val > 1) ok = false;
					tmp /= val;
				}
				if (ok) ans++;
			}
			return;
		}
		for (int i = 0; i <= vec[pos].second; i++) {
			dfs(val, pos + 1);
			val *= vec[pos].first;
		}
	};
	dfs(1ll, 0);
	save[n] = ans;
	return ans;
}

inline int func(long long n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	return get(n) + get(n - 1);
}

int main() {
  scanf("%d", &t);
  while (t--) {
    srand((unsigned)time(NULL));
    long long n; scanf("%lld", &n);
    printf("%d\n", func(n));
  }
  return 0;
}

