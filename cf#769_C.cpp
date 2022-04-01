#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int a, b;
int ans;
int getmin(int k)
{
	return k + 1 + min((a | (b + k)) - (b + k), ((a + k) | b) - b);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &a, &b);
		ans = b - a;
		for (int i = 0; i <= b - a; i++)
			ans = min(ans, getmin(i));
		printf("%d\n", ans);
	}
	return 0;
}
