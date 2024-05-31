#include<bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
typedef long long ll;
int n;
vector<ll> p, q;
ll ans[maxn];
bool sol()
{
	scanf("%d", &n);
	p.clear();
	q.clear();
	for (int i = 1; i <= n; i++)
	{
		ll x;
		scanf("%lld", &x);
		if (x >= 0)
			p.push_back(x);
		else
			q.push_back(x);
	}
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	if (q.empty()) return false;
	ll lim = p[p.size() - 1] - q[q.size() - 1], now = 0;
	int l = 0, r = 0;
	while (l < p.size() || r < q.size())
	{
		if (l < p.size() && now + p[l] < lim)
		{
			ans[l + r + 1] = p[l];
			now += p[l];
			l++;
		}
		else if (r < q.size() && now + q[r] < lim)
		{
			ans[l + r + 1] = q[r];
			now += q[r];
			r++;
		}
		else
			return false;
	}
	return true;
} 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		if (sol())
		{
			printf("Yes\n");
			for (int i = 1; i <= n; i++)
				printf("%lld ", ans[i]);
			printf("\n");
		}
		else
			printf("No\n");
	}
	return 0;
}

