#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, x;
void sol()
{
	scanf("%d%d", &n, &x);
	int ans = 0, lst = 0;
	for (int i = 1; i <= n; i++)
	{
		int now;
		scanf("%d", &now);
		ans = max(ans, now - lst);
		lst = now;
	}
	printf("%d\n", max(ans, 2 * (x - lst)));
} 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

