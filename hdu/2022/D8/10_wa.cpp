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
double getS(node *p, int n)
{
	sort(p, p + n);
	siz = 0;
	for (int i = 0; i < n; i++)
	{
		while (siz > 1 && cmul(q[siz - 1] - q[siz - 2], p[i] - q[siz - 1]) <= 0)
			siz--;
		q[siz++] = p[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		while (siz > 1 && cmul(q[siz - 1] - q[siz - 2], p[i] - q[siz - 1]) <= 0)
			siz--;
		q[siz++] = p[i];
	}
	ll S = 0;
	for (int i = 2; i < siz - 1; i++)
		S += abs(cmul(q[i] - q[0], q[i - 1] - q[0]));
	return (double)S * 0.5;
}
int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};
void sol()
{
	scanf("%d%d", &n, &qry);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &st[i].x, &st[i].y);
	double S[3];
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
	double A, B, C;
	C = S[0];
	A = S[2] * 0.5 - S[1] + S[0] * 0.5;
	B = S[1] - A - C;
	//printf("%f %f %f %f %f %f\n", S[0], S[1], S[2], A, B, C);
	for (int i = 1; i <= qry; i++)
	{
		double t;
		scanf("%lf", &t);
		printf("%.2f\n", A * t * t + B * t + C);
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
3 3
0 0
0 1
1 0
0
2
100000000
2 3
1 1
2 3
0
1
2
*/
