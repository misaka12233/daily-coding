#include<bits/stdc++.h>
using namespace std;

typedef double db;
const db eps = 1e-10;
struct pdd{
	db x, y;
	pdd operator - (const pdd &b) const
	{
		pdd t;
		t.x = x - b.x;
		t.y = y - b.y;
		return t;
	}
	bool operator < (const pdd &b) const
	{
		if (fabs(x - b.x) < eps) return y < b.y;
		return x < b.x;
	} 
};
db cross(pdd p1, pdd p2)
{
	return p1.x * p2.y - p2.x * p1.y;
}
db dot(pdd p1, pdd p2)
{
	return p1.x * p2.x + p1.y * p2.y;
}
db dis(pdd p1, pdd p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
db disLine(pdd p, pdd p1, pdd p2)
{
	return fabs(cross(p - p1, p - p2)) / dis(p1, p2);
}
db disSeg(pdd p, pdd p1, pdd p2)
{
	if (dot(p - p1, p1 - p2) > 0)
		return dis(p, p1);
	else if (dot(p - p2, p2 - p1) > 0) 
		return dis(p, p2);
	else
		return disLine(p, p1, p2);
}

int convexHull(pdd *p, pdd *res, int n)
{
	sort(p + 1, p + n + 1);
	int m = 0;
	res[++m] = p[1];
	for (int i = 2; i <= n; i++)
	{
		while (m > 1 && cross(res[m] - res[m - 1], p[i] - res[m - 1]) <= 0) m--;
		res[++m] = p[i];
	}
	int k = m;
	for (int i = n - 1; i >= 1; i--)
	{
		while (m > k && cross(res[m] - res[m - 1], p[i] - res[m - 1]) <= 0) m--;
		res[++m] = p[i];
	}
	return m;
}

const int maxn = 100000 + 10;
int n;
pdd p[maxn], res[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &p[i].x, &p[i].y);
	int m = convexHull(p, res, n);
	db ans = 0; 
	for (int i = 2; i <= m; i++)
		ans += dis(res[i], res[i - 1]);
	printf("%.2f\n", ans);
	return 0;
}

