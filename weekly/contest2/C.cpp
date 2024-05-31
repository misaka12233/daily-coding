#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
typedef long long ll;
int n;
ll m;
struct node{
	ll x, y;
};
node a[maxn], b[maxn];
int cnta, cntb;
bool cmp1(node x, node y)
{
	return x.x < y.x;
}
bool cmp2(node x, node y)
{
	if (x.y == y.y)
		return x.x < y.x;
	return x.y > y.y;
}
bool check()
{
	for (int i = 1; i <= cnta; i++)
	{
		if (m >= a[i].x)
			m += a[i].y - a[i].x;
		else
			return false;
	}
	for (int i = 1; i <= cntb; i++)
	{
		if (m >= b[i].x)
			m += b[i].y - b[i].x;
		else
			return false;
	}
	return true;
}
void init()
{
	cnta = cntb = 0;
}
void sol()
{
	scanf("%d%lld", &n, &m);
	init();
	for (int i = 1; i <= n; i++)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		if (x <= y)
		{
			cnta++;
			a[cnta].x = x;
			a[cnta].y = min(y, m); 
		}
		else
		{
			cntb++;
			b[cntb].x = x;
			b[cntb].y = min(y, m);
		}
	}
	sort(a + 1, a + cnta + 1, cmp1);
	sort(b + 1, b + cntb + 1, cmp2);
	if (check())
		puts("YES");
	else
		puts("NO");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

