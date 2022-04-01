#include<bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;

typedef long long ll;
typedef double db;

using namespace std;

int n;
int a[maxn], t, pos;
int size[2], cnt[maxn << 1], ans;
int chk(int x)
{
	if (a[x] < t) 
		return 0;
	else 
		return 1;
}
int main()
{
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == t)
			pos = i;
	}
	size[0] = size[1] = 0;
	cnt[0 + n]++;
	for(int i = pos - 1; i >= 1; i--)
	{
		size[chk(i)]++;
		cnt[size[0] - size[1] + n]++;
	}
	size[0] = size[1] = 0;
	ans += cnt[0 + n];
	for(int i = pos + 1; i <= n; i++)
	{
		size[chk(i)]++;
		ans += cnt[size[1] - size[0] + n];
	}
	printf("%d\n", ans);
	return 0;
}

