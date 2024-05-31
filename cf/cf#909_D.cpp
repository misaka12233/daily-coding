#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
typedef long long ll;
int n;
int a[maxn];
map<int, ll> cnt;
void sol()
{
	scanf("%d", &n);
	cnt.clear();
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		cnt[a[i]] = cnt[a[i]] + 1;
	}
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1]) continue;
		ll now = cnt[a[i]];
		ans += now * (now - 1) / 2;
		for (int x = a[i] * 2, k = 1; x <= a[n]; x = x * 2, k++)
		{
			if (x - a[i] == k)
				ans += cnt[a[i]] * cnt[x];
		}
	}
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}

