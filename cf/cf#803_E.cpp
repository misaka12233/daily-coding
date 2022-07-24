#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
const ll mod = 998244353;
int T;
int n, s;
int to[maxn], pos[maxn]; 
int a[maxn], b[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &s);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			pos[a[i]] = i;
			to[i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", b + i);
			if (b[i] != -1) to[b[i]] = i; 
		}
		ll cnt = 0, ans = 1;
		for (int i = 1; i <= 1 + s && i <= n; i++)
			if (b[pos[i]] == -1) 
				cnt++;
		for (int i = 1; i <= n; i++)
		{
			if (to[i])
			{
				if (a[to[i]] > i + s) 
					ans = 0;
			}
			else
			{
				ans = ans * max(cnt, 0ll) % mod;
				cnt--;
			}
			if (i + s + 1 <= n && b[pos[i + s + 1]] == -1) cnt++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

