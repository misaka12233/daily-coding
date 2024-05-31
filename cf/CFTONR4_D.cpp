#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int T;
void sol()
{
	int q;
	scanf("%d", &q);
	ll l = 1;
	ll r = 1ll * 1e9 * 1e9;
	while (q--)
	{
		int op;
		ll a, b, n;
		scanf("%d", &op);
		//(a-b)(n-2)+a+1 <= x <= (a-b)(n-1)+a
		if (op == 1)
		{
			scanf("%lld%lld%lld", &a, &b, &n);
			ll n_l, n_r;
			if (n != 1) n_l = (a - b) * (n - 2) + a + 1;
			else n_l = 1;
			n_r = (a - b) * (n - 1) + a;
			if (n_r >= l && n_l <= r)
			{
				l = max(l, n_l);
				r = min(r, n_r);
				printf("1 ");
			}
			else printf("0 ");
		}
		//(x-b-1)/(a-b)+1 == n == (x-a-1)/(a-b)+2
		else
		{
			scanf("%lld%lld", &a, &b);
			ll ans_l;
			if (l > a) ans_l = (l - b - 1) / (a - b) + 1;
			else ans_l = 1;
			ll ans_r;
			if (r > a) ans_r = (r - b - 1) / (a - b) + 1;
			else ans_r = 1;
			if (ans_l != ans_r) printf("-1 ");
			else printf("%lld ", ans_l);
		}
	}
	putchar('\n');
}
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

