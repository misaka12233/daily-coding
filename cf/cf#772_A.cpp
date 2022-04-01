#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
int ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int x;
		ans = 0;
		for (int i = 1; i <= n; i++)
		scanf("%d", &x), ans |= x;
		printf("%d\n", ans);
	}
	return 0;
}

