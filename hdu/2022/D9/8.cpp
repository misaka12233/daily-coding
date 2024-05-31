#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 10000000 + 10;
int n, q;
int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
vector<int> p;
bool inp[maxn];
void clear()
{
	for (auto x : p)
		inp[x] = false;
	p.clear();
}
void getpri(int x)
{
	int sqrx = sqrt(x);
	for (int i = 2; i <= sqrx && x != 1; i++)
	{
		if (x % i == 0)
		{
			if (!inp[i])
			{
				inp[i] = true;
				p.push_back(i);
			}
			while (x % i == 0) x /= i;
		}
	}
	if (x != 1)
	{
		if (!inp[x])
		{
			inp[x] = true;
			p.push_back(x);
		}
	}
}
/*
int qry(int x)
{
	int ans = 0;
	int tot = 1 << p.size();
	for (int k = 1; k < tot; k++)
	{
		ll now = 1;
		int op = -1;
		for (int i = 0, bit = 1; i < p.size(); i++, bit <<= 1)
			if (k & bit)
				now = now * p[i], op *= -1;
		ans += op * (1ll * x / now);
	}
	return x - ans;
}
*/
int dfs_qry(int now, int pro, int op, int x)
{
	int res = 0;
	for (int i = now + 1; i < p.size(); i++)
	{
		if (1ll * pro * p[i] > x) break;
		res += dfs_qry(i, pro * p[i], op * -1, x);
	}
	res += op * (x / pro);
	return res;
}
int main()
{
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	scanf("%d%d", &n, &q);
	while (q--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if (gcd(u, v) == 1)
			puts("1 1");
		else
		{
			if (u > v) swap(u, v);
			clear();
			getpri(u);
			getpri(v);
			sort(p.begin(), p.end());
			printf("2 %d\n", -dfs_qry(-1, 1, -1, n) + (gcd(u, v) == 2));
		}
	}
	return 0;
}

