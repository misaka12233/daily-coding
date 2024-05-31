#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
void sol()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int x, lst = 0;
	bool res = true;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (x < lst) res = false;
		lst = x;
	}
	if (res || k > 1) puts("YES");
	else puts("NO");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

