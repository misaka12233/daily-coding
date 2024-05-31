#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
typedef long long ll;
int n;
ll a[maxn], b[maxn];
void sol()
{
	ll ans = 0, mnr = inf, mxl = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	for (int i = 1; i <= n; i++)
		scanf("%lld", b + i);
	for (int i = 1; i <= n; i++)
	{
		ans = ans + abs(a[i] - b[i]);
		if (a[i] < b[i])
		{
			mnr = min(mnr, b[i]);
			mxl = max(mxl, a[i]);
		}
		else
		{
			mnr = min(mnr, a[i]);
			mxl = max(mxl, b[i]);
		}
	}
	if (mxl > mnr)
		ans = ans + (mxl - mnr) * 2;
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

