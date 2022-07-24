#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const ll mod = 1e9 + 7;
int T;
int n;
ll pos[maxn]; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			pos[x] = i;
		}
		ll l = min(pos[0], pos[1]), r = max(pos[0], pos[1]);
		ll opt = r - l - 1;
		ll ans = 1;
		for (int i = 2; i < n; i++)
		{
			if (pos[i] < l) opt += l - pos[i] - 1, l = pos[i];
			else if (pos[i] > r) opt += pos[i] - r - 1, r = pos[i];
			else ans = ans * opt % mod, opt--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

