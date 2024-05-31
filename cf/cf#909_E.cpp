#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
int a[maxn];
int sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	a[n + 1] = inf;
	int l = 1, r = n;
	while (l <= r)
	{
		while (l < r && a[r] >= a[l])
		{
			if (a[r] > a[r + 1]) return -1;
			r--;
		}
		l++;
	}
	return l - 2;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		printf("%d\n", sol());
	return 0;
}

