#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int maxn = 100000 + 10;
int n, q;
int x[3][3];
int p[3][maxn];
int cnt[3], len[3][maxn];
int num[3][maxn], circle[3][maxn];
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exgcd(b, a % b, y, x);
	y = y - a / b * x;
	return gcd;
}
void dfs(int now, int k, int rk)
{
	num[k][now] = rk;
	circle[k][now] = cnt[k];
	int nxt = now, st = (k + 2) % 3;
	int i = st;
	do
	{
		nxt = p[i][nxt];
		i = (i + 2) % 3;
	}while (i != st);
	if (circle[k][nxt] == 0)
		dfs(nxt, k, rk + 1);
	else
		len[k][cnt[k]] = rk + 1;
}
bool same_circle(int *x, int *y)
{
	for (int i = 0; i < 3; i++)
		if (circle[i][x[i]] != circle[i][y[i]]) 
			return false;
	return true;
}
pll excrt(pll l, pll r) 
{
    ll r1 = l.first, m1 = l.second;
    ll r2 = r.first, m2 = r.second;
    if (r1 == -1 || r2 == -1) return {-1, -1};
    ll d, l1, l2;
    d = exgcd(m1, m2, l1, l2);
    if ((r2 - r1) % d) return {-1, -1};
    ll L = m1 * m2 / d;
    ll R = ((r1 + (r2 - r1) / d * l1 % L * m1) % L + L) % L;
    return {R, L};
}
ll getans()
{
	ll ans = -1;
	int y[3];
	for (int k = 0; k < 3; k++)
		scanf("%d", y + k);
	ll R[3], L[3];
	for (int k = 0; k < 3; k++)
	{
		if (!same_circle(x[k], y)) continue;
		for (int i = 0; i < 3; i++)
		{
			L[i] = len[i][circle[i][y[i]]];
			R[i] = (num[i][y[i]] - num[i][x[k][i]] + L[i]) % L[i];
		}
		pll A(R[0], L[0]);
		pll B(R[1], L[1]);
		pll C(R[2], L[2]);
		pll res = excrt(A, excrt(B, C));
		if (res.first != -1)
		{
			if (ans == -1) ans = res.first * 3 + k;
			else ans = min(ans, res.first * 3 + k);
		}
	}
	return ans;
}
int main()
{
	scanf("%d", &n);
	for (int k = 0; k < 3; k++)
		for (int i = 1; i <= n; i++)
			scanf("%d", &p[k][i]);
	x[0][0] = x[0][1] = x[0][2] = 1;
	for (int k = 1; k < 3; k++)
		for (int i = 0; i < 3; i++)
			x[k][i] = p[i][x[k - 1][(i + 1) % 3]];
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (circle[k][i] == 0)
			{
				cnt[k]++;
				dfs(i, k, 0);
			}
		}
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
		printf("%lld\n", getans());
	return 0;
}

