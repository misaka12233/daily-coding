#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n;
char s[maxn];
int cnt[maxn];
struct node{
	int pos;
	char c;
}lst[30];
int m;
bool cmp(node x, node y)
{
	return x.pos < y.pos;
}
int main()
{
	scanf("%d", &n);
	printf("? 1 1\n");
	fflush(stdout);
	char tmp[3];
	scanf("%s", tmp);
	s[0] = tmp[0];
	cnt[1] = 1;
	m++;
	lst[m].pos = 1;
	lst[m].c = s[0];
	for (int i = 2; i <= n; i++)
	{
		printf("? 2 1 %d\n", i);
		fflush(stdout);
		scanf("%d", cnt + i);
		if (cnt[i] == cnt[i - 1])
		{
			sort(lst + 1, lst + m + 1, cmp);
			int l = 1, r = m, mid, x;
			while (l < r)
			{
				mid = l + r >> 1;
				printf("? 2 %d %d\n", lst[mid].pos + 1, i);
				fflush(stdout);
				scanf("%d", &x);
				if (x == m - mid) l = mid + 1;
				else r = mid;
			}
			s[i - 1] = lst[l].c;
			lst[l].pos = i;
		}
		else
		{
			printf("? 1 %d\n", i);
			fflush(stdout);
			scanf("%s", tmp);
			s[i - 1] = tmp[0];
			m++;
			lst[m].pos = i;
			lst[m].c = s[i - 1];
		}
	}
	printf("! %s", s);
	fflush(stdout);
	return 0;
}

