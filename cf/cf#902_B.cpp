#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<ll, int> pli;
const int maxn = 100000 + 10;
ll p;
int n;
pli x[maxn];
void sol()
{
	scanf("%d%lld", &n, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i].second);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &x[i].first);
	sort(x + 1, x + n + 1);
	ll ans = p;
	int now = 1;
	n--;
	while (n)
	{
		if (x[now].first >= p)
		{
			ans += p * n;
			n = 0;
		}
		else if (x[now].second >= n)
		{
			ans += x[now].first * n;
			n = 0;
		}
		else
		{
			ans += x[now].first * x[now].second;
			n -= x[now].second;
			now++;
		}
	}
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)	sol();
	return 0;
}

