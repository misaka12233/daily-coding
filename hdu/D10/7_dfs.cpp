#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
map< pair<ll,int> , int> mp;
int dfs(ll x, int op)
{
	if (mp.count({x,op})) return mp[{x,op}];
	int res = (op ? 0 : inf);
	bool canP = false;
	ll now = 1;
	for (int i = 1; i <= n; i++, now <<= 1)
	{
		ll pre = now >> 1, nxt = now << 1;
		if ((x&pre) || (x&now) || (x&nxt)) continue;
		canP = true;
		if (op) res = max(res, dfs(x | now, op ^ 1) + 1);
		else res = min(res, dfs(x | now, op ^ 1) + 1);
	}
	if (canP) mp[{x,op}] = res;
	else mp[{x,op}] = 0;
	return mp[{x,op}];
}
void sol()
{
	char s[10];
	scanf("%d", &n);
	scanf("%s", s);
	mp.clear();
	if (s[0] == 'A') printf("%d\n", dfs(0, 0));
	else printf("%d\n", dfs(0, 1));
}
int T;
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}
/*
5 1 9
1 2 1
1 2
2 3
2 4
2 5
3 4
3 5
4 5
3 4
2 4
*/
