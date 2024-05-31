#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
bool sol()
{
	int n;
	scanf("%d", &n);
	bool ans = false;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (i >= x) ans = true;
	}
	return ans;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		if (sol()) puts("YES");
		else puts("NO");
	}
	return 0;
}

