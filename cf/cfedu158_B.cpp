#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
void sol()
{
	scanf("%d", &n);
	int lst = 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		ans = ans + max(0, x - lst);
		lst = x;
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

