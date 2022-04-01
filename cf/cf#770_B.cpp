#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int T;
ll n, x, y;
ll a[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld", &n, &x, &y);
		for (int i = 1; i <= n; i++)
		scanf("%lld", a + i), x ^= a[i];
		if (y % 2 == x % 2) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
