#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int T;
char s[maxn], ans[maxn]; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(ans, 0, sizeof(ans));
		scanf("%s", s);
		int n = strlen(s), m = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '-' || s[i] == '(' || s[i] == ')' || s[i] == ',' || (s[i] >= '0' && s[i] <= '9'))
			{
				ans[m] = s[i];
				m++;
			}
		}
		printf("%s\n", ans);
	}
	return 0;
}

