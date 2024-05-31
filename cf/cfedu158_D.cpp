#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;
int n;
int a[maxn], l[maxn], r[maxn];
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		l[i] = a[i] + i - 1;
		r[i] = a[i] + n - i;
	}
	r[0] = l[n + 1] = 0;
	for (int i = n; i >= 1; i--)
		l[i] = max(l[i + 1], l[i]);
	for (int i = 1; i <= n; i++)
		r[i] = max(r[i - 1], r[i]);
	int ans = inf;
	for (int i = 1; i <= n; i++)
		ans = min(ans, max(max(r[i - 1], l[i + 1]), a[i]));
	printf("%d\n", ans);
} 
int main()
{
	//int T;
	//scanf("%d", &T);
	//while (T--) 
	sol();
	return 0;
}

