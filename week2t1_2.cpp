#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int T;
int n, m;
int a[maxn], gap[maxn]; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		scanf("%d", a + i), gap[n - i + 1] = m - a[i];
		bool ans = false;
		for (int i = 1, j = 1; j <= n; j++)
		{
			while (a[i] < gap[j] && i + 1 <= n) i++;
			if (a[i] == gap[j] && n - i + 1 != j) 
			{
				ans = true;
				break;
			}
		}
		if (ans) puts("Yes");
		else puts("No");
	}
	return 0;
}

