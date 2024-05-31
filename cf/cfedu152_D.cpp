#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
int a[maxn];
int col[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	bool have2 = false;
	int lst = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != 0)
		{
			if (a[i - 1] == 0)
			{
				lst = i;
				cnt++;
				have2 = false;
			}
			col[i] = 1;
			if (a[i] == 2)
				have2 = true;
			if (a[i + 1] == 0)
			{
				if (have2)
					col[lst - 1] = col[i + 1] = 1;
				else if (lst - 1 >= 1 && col[lst - 1] == 0)
					col[lst - 1] = 1;
				else
					col[i + 1] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (col[i] == 0)
			cnt++;
	printf("%d\n", cnt);
	return 0;
}

