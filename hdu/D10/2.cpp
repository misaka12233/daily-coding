#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int mod = 998244353;
struct node{
	int l, r;
	node(int l, int r)
	{
		this->l = l;
		this->r = r;
	}
	node(){
	}
};
node t[maxn];
bool cmp(node x, node y)
{
	if (x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}
vector<node> q;
int n, m;
int c[2][2] = {1, 1, 1, 2};
void mul(int a[][2], int b[][2])
{
	int tmp[2][2] = {0};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
				tmp[i][j] = (tmp[i][j] + 1ll * b[i][k] * a[k][j] % mod) % mod;
		}
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			a[i][j] = tmp[i][j];
}
void ksm(int now[][2], int k)
{
	int a[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			a[i][j] = c[i][j];
	int res[2][2] = {1,0,0,1};
	while (k)
	{
		if (k&1) mul(res, a);
		k >>= 1;
		mul(a, a);
	}
	mul(now, res);
}
void sol()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x >= y)
		{
			x++;
			t[i].l = y;
			t[i].r = x;
		}
		else
		{
			y++;
			t[i].l = x;
			t[i].r = y;
		}
	}
	sort(t + 1, t + m + 1, cmp);
	q.clear();
	int l = 0, r = 0;
	for (int i = 1; i <= m; i++)
	{
		if (t[i].l >= r)
		{
			q.push_back(node(l, r));
			l = t[i].l;
			r = t[i].r;
		}
		else r = max(r, t[i].r);
	}
	q.push_back(node(l, r));
	int now = 0;
	int dp[2][2] = {1,0,0,0};
	for (auto x : q)
	{
		if (x.l == 0 && x.r == 0) continue;
		ksm(dp, x.l - now + 1);
		dp[0][0] = 0;
		now = x.r;
	}
	ksm(dp, n - now);
	printf("%d\n", (dp[0][0] + dp[1][0]) % mod);
}
int main()
{
	int st = clock();
	int T;
	scanf("%d", &T);
	while (T--) sol();
	int ed = clock();
	printf("%d\n", ed - st);
	return 0;
}

