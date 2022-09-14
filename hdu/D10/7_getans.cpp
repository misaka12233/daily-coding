#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
map<pil, pil> mp;
char s[10];
pil dfs(ll x, int op)
{
	if (mp.count({op,x})) return mp[{op,x}];
	pil res = {(op ? 0 : inf), x};
	bool canP = false;
	ll now = 1;
	for (int i = 1; i <= n; i++, now *= 3)
	{
		ll pre = now / 3, nxt = now * 3, nnxt = nxt * 3;
		if (((x%now) >= pre && pre > 0) || (x%nxt) >= now || (x%nnxt) >= nxt) continue;
		canP = true;
		if (op) res = max(res, dfs(x + now, op ^ 1));
		else res = min(res, dfs(x + now * 2, op ^ 1));
	}
	res.first += 1;
	if (canP) mp[{op,x}] = res;
	else mp[{op,x}] = {0, x};
	return mp[{op,x}];
}
void sol()
{
	scanf("%d", &n);
	scanf("%s", s);
	mp.clear();
	pil res;
	if (s[0] == 'A') res = dfs(0, 0);
	else res = dfs(0, 1);
	printf("%d\n", res.first);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", res.second % 3);
		res.second /= 3;
	}
	puts("");
}
int T;
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

