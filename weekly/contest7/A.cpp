#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
void sol()
{
	long long x;
	int ans = 0;
	scanf("%lld", &x);
	for (int i = 63; i > 0; i--)
	 	while (x >= (1ll << i) - 1)
	 		x -= (1ll << i) - 1, ans++;
	printf("%d\n", ans - 1);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

