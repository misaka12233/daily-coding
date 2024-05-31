#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int n, m, k;
int a[maxn];
void sol()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	int st = 1;
	if (a[n] == a[1])
	{
		st = n;
		while (st > 1 && a[st - 1] == a[1]) 
			st--;
	}
	int i = st, lst = 0, len = 0, ans = 0;
	bool t = false;
	do 
	{
		if (a[i] != a[lst])
		{
			if (len >= k) t = true;
			ans += (len + k - 1) / k;
			len = 1;
		}
		else
			len++;
		lst = i;
		i = i % n + 1;
	}while (i != st);
	if (len >= k) t = true;
	ans += (len + k - 1) / k;
	if (t)
		printf("%d\n", ans);
	else
		puts("-1");
} 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}

