#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int a, b, n;
void sol()
{
	scanf("%d%d%d", &a, &b, &n);
	long long ans = b;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		ans = ans + min(x, a - 1);
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

