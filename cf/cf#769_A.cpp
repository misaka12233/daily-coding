#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
char s[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		bool ans = true;
		scanf("%s", s);
		for (int i = 0; i < n; i++)
		{
			if (s[i] == s[i + 1] && i + 1 < n)
				ans = false;
			if (s[i] == s[i + 2] && i + 2 < n)
				ans = false;
		}
		if (ans) puts("YES");
		else puts("NO");
	}
	return 0;
}

