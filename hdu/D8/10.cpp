#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
struct node{
	int x, y;
	node operator -(const node &b) const
	{
		node tmp;
		tmp.x = x - b.x;
		tmp.y = y - b.y;
		return tmp;
	}
	bool operator <(const node &b) const
	{
		if (x == b.x) return y < b.y;
		return x < b.x;
	}
};
int n, m, qry;
node st[maxn];
node p[maxn << 2];
node q[maxn << 2];
int siz;
ll cmul(node a, node b)
{
	return 1ll * a.x * b.y - 1ll * a.y * b.x;
}
ll getS(node *p, int n)
{
	sort(p, p + n);
	int now = 0;
	for (int j = 0; j < n; j++, now++)
	{
		while (p[j].x == p[j + 1].x && p[j].y == p[j + 1].y && j < n) j++;
		p[now] = p[j];
	}
	n = now;
	q[0] = p[0], q[1] = p[1];
	siz = 2;
	for (int i = 2; i < n; i++)
	{
		while (siz > 1 && cmul(q[siz - 1] - q[siz - 2], p[i] - q[siz - 2]) <= 0)
			siz--;
		q[siz++] = p[i];
	}
	q[siz++] = p[n - 2];
	for (int i = n - 3; i >= 0; i--)
	{
		while (siz > 1 && cmul(q[siz - 1] - q[siz - 2], p[i] - q[siz - 2]) <= 0)
			siz--;
		q[siz++] = p[i];
	}
	ll S = 0;
	for (int i = 2; i < siz - 1; i++)
		S += abs(cmul(q[i] - q[0], q[i - 1] - q[0]));
	return S;
}
int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};
void sol()
{
	scanf("%d%d", &n, &qry);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &st[i].x, &st[i].y);
	ll S[3];
	for (int k = 0; k < 3; k++)
	{
		m = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				p[m].x = st[i].x + k * dirx[j];
				p[m].y = st[i].y + k * diry[j];
				m++;
			}
		}
		S[k] = getS(p, m);
	}
	ll A, B, C;
	C = S[0] * 2;
	A = S[2] - S[1] * 2 + S[0];
	B = S[1] * 2 - A - C;
	//printf("%lld %lld %lld %lld %lld %lld\n", S[0], S[1], S[2], A, B, C);
	while (qry--)
	{
		ll t, ans;
		scanf("%lld", &t);
		ans = A * t * t + B * t + C;
		ans = ans / 2;
		if (ans & 1) printf("%lld.5\n", ans / 2);
		else printf("%lld.0\n", ans / 2);
		/*m = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				p[m].x = st[i].x + t * dirx[j];
				p[m].y = st[i].y + t * diry[j];
				m++;
			}
		}
		ll tmp = getS(p, m);
		printf("%lld %lld", ans, tmp);
		if (ans == tmp) puts("Nice");
		else puts("GG");*/
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}
/*
2
4 2
6 6
4 6
5 1
2 6
3
4
*/
