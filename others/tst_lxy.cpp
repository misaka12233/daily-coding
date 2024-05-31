#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int T;
int n, k;
int s[maxn];
bool sol()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", s + i);
	if (k == 1) return true;
	for (int i = 3; i <= k; i++)
		if (s[i] - s[i - 1] < s[i - 1] - s[i - 2]) 
			return false;
	return (1ll * (s[2] - s[1]) * (n - k + 1) - s[1] >= 0);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		if (sol()) puts("Yes");
		else puts("No");
	}
	return 0;
}

