#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int n, m, q;
struct node{
	int typ, num, is_r;
};
node t[maxn];
bool vis[2][maxn];
long long ans;
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= q; i++)
	{
		char s[10], op[10];
		int num;
		scanf("%s%d%s", s, &num, op);
		if (s[0] == 'r')
		{
			t[i].typ = (op[1] == 'n') ? 1 : 0;
			t[i].is_r = 1;
			t[i].num = num;
		}
		else
		{
			t[i].typ = (op[1] == 'n') ? 1 : 0;
			t[i].is_r = 0;
			t[i].num = num;
		}
	}
	
	for (int i = q; i >= 1; i--)
	{
		if (!vis[t[i].is_r][t[i].num])
		{
			vis[t[i].is_r][t[i].num] = true;
			if (t[i].is_r == 1)
			{
				n--;
				if (t[i].typ == 1) 
					ans = ans + m;
			}
			else
			{
				m--;
				if (t[i].typ == 1) 
					ans = ans + n;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

