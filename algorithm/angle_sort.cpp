#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
struct vec{
	long double x;
	long double y;
	int id;
	long double operator * (vec b) {return x * b.x + y * b.y;}
};
int n;
vec p[maxn];
double cross(vec a, vec b) {return a.x*b.y - a.y*b.x;}
long double angle(vec a)
{
	return atan2(a.y, a.x);
}
bool cmp(vec a, vec b)
{
	return angle(a) < angle(b);
}
long double calc(vec a, vec b)
{
	return fabs(atan2(fabs(cross(a,b)), a*b));
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%Lf", &p[i].x);
		scanf("%Lf", &p[i].y);
		p[i].id = i;
	}
	sort(p + 1, p + n + 1, cmp);
	int r1 = n, r2 = 1;
	for (int i = 1; i < n; i++)
	{
		if (calc(p[r1], p[r2]) > calc(p[i], p[i + 1]))
		{
			r1 = i;
			r2 = i + 1;
		}
	}
	printf("%d %d\n", p[r1].id, p[r2].id);
	return 0;
}

