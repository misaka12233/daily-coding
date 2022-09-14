#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int n;
int a[maxn];
int b[maxn];
ll ans1, ans2;
int getdel(int i, int op)
{
	if (op == 0) return max(0, b[i - 1] - b[i] + 1);
	else return max(0, b[i] - b[i - 1] + 1);
}
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	ans1 = 0;
	for (int i = 1; i <= n; i++) b[i] = a[i];
	for (int i = 2; i <= n; i++)
	{
		int del = getdel(i, i & 1);
		if (del)
		{
			ans1 = ans1 + del;
			b[i] += ((i&1)? -1 : 1) * del;
		}
	}
	ans2 = 0;
	for (int i = 1; i <= n; i++) b[i] = a[i];
	for (int i = 2; i <= n; i++)
	{
		int del = getdel(i, (i + 1) & 1);
		if (del)
		{
			ans2 = ans2 + del;
			b[i] += (((i+1)&1)? -1 : 1) * del;
		}
	}
	printf("%lld\n", min(ans1, ans2));
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

