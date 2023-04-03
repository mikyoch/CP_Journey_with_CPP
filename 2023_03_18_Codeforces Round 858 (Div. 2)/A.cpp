#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
const int mod = 998244353;
int n;
typedef long long ll;
// #define int ll
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a % mod;
		a = a * a % mod, n >>= 1;
	}
	return ans;
}
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
inline ll Hash(int x, int y)
{
	return 1ll * x * n + y;
}
// unordered_map<ll, ll> ans;
gp_hash_table<ll, ll> ans;
int a[1000010], fa[1000010];
inline ll Work(int u, int v)
{
	if(!u)
		return 0;
	if(u > v)
		swap(u, v);
	ll H = Hash(u, v);
	if(ans.find(H) != ans.end())
		return ans[H];
	return ans[H] = 1ll * a[u] * a[v] + Work(fa[u], fa[v]);
}
inline ll Solve(int u, int v)
{
	int T = 1000;
	ll ans = 0;
	while(T-- && u)
	{
		ans += 1ll * a[u] * a[v];
		u = fa[u], v = fa[v];
	}
	if(u)
		ans += Work(u, v);
	return ans;
}
signed main()
{
	int q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	fa[1] = 0;
	for(int i = 2; i <= n; i++)
		scanf("%d", &fa[i]);
	while(q--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%lld\n", Solve(u, v));
	}
	return 0;
}

