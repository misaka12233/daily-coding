#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n, k;
pii a[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].first);
		for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].second);
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			if (k >= a[i].first)
			k += a[i].second;
		}
		printf("%d\n", k);
	}
	return 0;
}

