#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, k;
int b[maxn];
bool vis[maxn];
bool sol()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i), vis[i] = false;
	int now = n;
	while (k > 0 && b[now] <= n)
	{
		if (vis[now]) return true;
		vis[now] = true;
		now = (now - b[now] + n) % n;
		k--;
	}
	return k == 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) 
	{
		if (sol()) puts("Yes");
		else puts("No");
	}
	return 0;
}

