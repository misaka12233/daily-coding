#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n;
pii pos[maxn];
ll crossProduct(pii a, pii b) //向量叉积的大小
//数值绝对值上等于两个向量组成的平行四边形面积 
{
	return a.first * b.second - b.first * a.second;
}
ll Xmul(pii a, pii b, pii c)
{
	pii tmp1, tmp2;
	tmp1.first = b.first - a.first;
	tmp1.second = b.second - a.second;
	tmp2.first = c.first - a.first;
	tmp2.second = c.second - a.second;
	return crossProduct(tmp1, tmp2);
}
ll getDis(pii a, pii b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld%lld", &pos[i].first, &pos[i].second);	
		pos[n + 1] = pos[1];
		ll ans = 0;
		int ans1 = 0, ans2 = 0; 
		for (int i = 1, j = 2; i <= n; i++)
		{
			while (abs(Xmul(pos[i], pos[i + 1], pos[j])) < abs(Xmul(pos[i], pos[i + 1], pos[j % n + 1])))
			//比较两个平行四边形面积来比较同一底边上的高，得到距离较远的 
				j = j % n + 1;
			ll now;
			int now1, now2 = j;
			if (getDis(pos[i], pos[j]) > getDis(pos[i + 1], pos[j]))
			{
				now = getDis(pos[i], pos[j]);
				now1 = i;
			}
			else
			{
				now = getDis(pos[i + 1], pos[j]);
				now1 = i + 1;
			}
			if (now > ans)
			{
				ans = now;
				ans1 = now1;
				ans2 = now2;
			}
		}
		printf("%d %d %lld\n", ans1 - 1, ans2 - 1, ans);
	}
	return 0;
}

