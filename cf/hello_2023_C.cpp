#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
typedef long long ll;
ll a[maxn];
priority_queue<ll> q;
void sol()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	while (!q.empty()) q.pop();
	ll sum = 0;
	int ans = 0;
	for (int i = m; i >= 2; i--)
	{
		sum += a[i];
		q.push(a[i]);
		while (sum > 0)
		{
			sum -= 2 * q.top();
			ans++;
			q.pop();
		}
	}
	while (!q.empty()) q.pop();
	sum = 0;
	for (int i = m + 1; i <= n; i++)
	{
		sum += a[i];
		q.push(-a[i]);
		while (sum < 0)
		{
			sum += 2 * q.top();
			ans++;
			q.pop();
		}
	}
	printf("%d\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

