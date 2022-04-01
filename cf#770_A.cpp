#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
char s[maxn]; 
int n, k;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		bool huiwen = true;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != s[n - i - 1])
			{
				huiwen = false;
				break;
			}
		}
		if (!huiwen && k >= 1) puts("2");
		else puts("1");
	}
	return 0;
}

