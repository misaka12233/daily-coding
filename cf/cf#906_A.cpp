#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
char a[maxn << 3];
int ans[maxn << 3];
void sol()
{
	scanf("%d", &n);
	scanf("%s", a + 1);
	int cnt1 = 0; 
	for (int i = 1; i <= n; i++)
		if (a[i] == '1')
			cnt1++;
	if (cnt1 == n - cnt1)
	{
		int l = 1, r = n;
		int s = 0;
		while (l <= r)
		{
			if (a[l] != a[r]) l++, r--;
			else
			{
				if (a[l] == '0') 
				{
					ans[++s] = r;
					a[r + 1] = '0';
				}
				else
				{
					ans[++s] = l - 1;
					for (int i = r; i >= l; i--)
						a[i + 2] = a[i];
					a[l + 1] = '1';
				}
				l++, r++; 
			}
		}
		printf("%d\n", s);
		for (int i = 1; i <= s; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	else puts("-1");
}
int main()
{
	//freopen("906A.out", "w", stdout);
	//freopen("906A.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

