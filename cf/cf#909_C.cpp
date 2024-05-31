#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
typedef long long ll;
const ll inf = 1ll * 0x3f3f3f3f * maxn;
int n;
ll a[maxn];
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	ll now, ans;
	now = ans = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (((a[i - 1] ^ a[i]) & 1) && now > 0)
			now += a[i];
		else
			now = a[i];
		ans = max(ans, now);
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

