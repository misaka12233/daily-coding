#include<bits/stdc++.h>
using namespace std;
typedef pair<double, double> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
const double pi = acos(-1);
int n;
set<pii> s[maxn];
double x[maxn], y[maxn], r[maxn];
void getpii(int up, int down)
{
	double dx = x[up] - x[down], dy = y[up] - y[down];
	double d = sqrt(dx * dx + dy * dy);
	if (d > r[up] + r[down] || d < r[down] - r[up]) return;
	if (d < r[up] - r[down]) 
	{
		s[down].insert({0, pi * 2});
		return;
	}
	double A = acos((d * d + r[down] * r[down] - r[up] * r[up]) / (d * r[down] * 2));
	double B = acos(dx / d);
	if (dy < 0) B = pi * 2 - B;
	if (B - A < 0)
	{
		s[down].insert({B - A + pi * 2, pi * 2});
		s[down].insert({0, B + A});
	}
	else if (B + A > pi * 2)
	{
		s[down].insert({B - A, pi * 2});
		s[down].insert({0, B + A - pi * 2});
	}
	else s[down].insert({B - A, B + A});
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf%lf", x + i, y + i, r + i);
		for (int j = 1; j < i; j++)
			getpii(i, j);
	}
	double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i].empty())
		{
			ans += pi * r[i] * 2;
			continue;
		}
		pii tmp = *s[i].begin();
		double st = tmp.first, ed = tmp.second, tot = 2 * pi;
		for (auto j : s[i])
		{
			if (j.first > ed)
			{
				tot -= ed - st;
				st = j.first;
				ed = j.second;
			}
			else ed = max(ed, j.second);
		}
		tot -= ed - st;
		ans += tot * r[i];
	}
	printf("%.9f\n", ans);
	return 0;
}

