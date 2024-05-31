#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
typedef long long ll;
int n;
ll a[maxn];
ll sum[maxn];
int getpos(int l, int r, ll ldown, int x)
{
	while (l < r)
	{
		int mid = l + r >> 1;
		if (sum[mid] - sum[l - 1] - ldown >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}
void sol()
{
	scanf("%d", &n);
	ll s = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", a + i);
		s += a[i];
		sum[i] = s;
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	ll ldown = 0;
	while (s > a[r] + a[r])
	{
		int p = getpos(l, r - 1, ldown, a[r]);
		s -= a[r] + a[r];
		ans += a[r] + 1;
		ldown = a[p] - (sum[p] - sum[l - 1] - a[r]);
		l = p;
		r--;
		if (ldown == a[p])
		{
			l++;
			ldown = 0;
		}
	}
	if (s == 1) ans += 1;
	else ans += (s&1) + s / 2 + 1;
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

