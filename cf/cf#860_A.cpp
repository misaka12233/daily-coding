#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
int a[maxn], b[maxn];
bool sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i);
	for (int i = 1; i <= n; i++)
		if ((a[i] > a[n] || b[i] > b[n]) && (a[i] > b[n] || b[i] > a[n]))
			return false;
	return true;
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

