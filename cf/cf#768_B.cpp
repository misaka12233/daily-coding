#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n;
int a[maxn]; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		int ans = 0, now = n - 1;
		while (a[now] == a[n] && now >= 1) now--;
		while (now >= 1)
		{
			ans++;
			now -= n - now;
			while (a[now] == a[n] && now >= 1) now--;
		}
		printf("%d\n", ans);
	}
	return 0;
}

