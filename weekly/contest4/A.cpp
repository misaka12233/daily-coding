#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
typedef long long ll;
int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main()
{
	ll A, B, C, D;
	scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
	ll ans = 0;
	for (int i = 1; i < 999; i++)
		for (int j = 1; i + j <= 999; j++)
		{
			if (gcd(i, j) != 1) continue;
			ll li = (A - 1) / i + 1, ri = B / i;
			ll lj = (C - 1) / j + 1, rj = D / j;
			ans += max(0ll, min(ri, rj) - max(li, lj) + 1);
		}
	printf("%lld\n", ans);
	return 0;
}

