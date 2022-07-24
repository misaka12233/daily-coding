#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
const double eps = 0.00000001;
int n, m, k, T;
int pos[maxn][2];
double L[maxn];
double f[maxn];
int q[maxn], head, tail;
/*double x1(int a)
{
	return L[a] / (a - 1);
}
double y1(int a)
{
	return L[a] - L[a] / (a - 1) * a;
}*/
double getsum1(int i,int j)
{
	return L[j] / (j - 1) * (i - j) + L[j];
}
/*double cj1(int a,int b,int c)
{
	double xa=x1(a),xb=x1(b),xc=x1(c);
	double ya=y1(a),yb=y1(b),yc=y1(c);
	return (xb-xa)*(yc-ya)-(xc-xa)*(yb-ya);
}
double x2(int a)
{
	return - L[a] / (m - a);
}
double y2(int a)
{
	return L[a] + L[a] / (m - a) * a;
}*/
double getsum2(int i,int j)
{
	return L[j] / (m - j) * (j - i) + L[j];
}
/*double cj2(int a,int b,int c)
{
	double xa=x2(a),xb=x2(b),xc=x2(c);
	double ya=y2(a),yb=y2(b),yc=y2(c);
	return (xb-xa)*(yc-ya)-(xc-xa)*(yb-ya);
}*/
double cj(double x1, double y1, double x2, double y2, double x3, double y3)
{
	return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}
void sol()
{
	for (int i = 1; i <= m; i++)
		f[i] = L[i];
	int now = 1;
	for (int i = 2; i <= m; i++)
	{
		if (cj(0, 1, L[now], now, L[i], i) > eps)
			now = i;
		f[i]=min(f[i], getsum1(i,now));
		/*for (int j = 1; j <= i; j++)
			f[i] = min(f[i], getsum1(i, j));*/
	}
	now = m;
	for (int i = m - 1; i >= 1; i--)
	{
		if (cj(0, m, L[now], now, L[i], i) < eps)
			now = i;
		f[i]=min(f[i], getsum2(i,now));
		/*for (int j = m; j >= i; j--)
			f[i] = min(f[i], getsum2(i, j));*/
	}
	long long ans = 0;
	for (int i = 1; i <= m; i++) 
	{
		long long tmp = f[i];
		if (fabs(f[i] - tmp) <= eps) tmp--;
		ans = ans + tmp;
	}
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &T);
	for (int i = 1; i <= k; i++)
		scanf("%d%d", &pos[i][0], &pos[i][1]);
	for (int i = 1; i <= T; i++)
	{
		int p, x, y;
		scanf("%d%d%d", &p, &x, &y);
		pos[p][0] = x;
		pos[p][1] = y;
		for (int i = 1; i <= m; i++) L[i] = n + 1;
		for (int i = 1; i <= k; i++)
			L[pos[i][1]] = min(L[pos[i][1]], 1.0 * pos[i][0]);
		sol();
	}
	return 0;
}

