#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int fa[maxn], rk[maxn];
void link(int x, int y)
{
	if (rk[x] > rk[y]) fa[y] = x;
	else
	{
		fa[x] = y;
		if (rk[x] == rk[y]) rk[y]++;
	}
}
int getfa(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
int main()
{
	for (int i = 1; i <= 16; i++)
		fa[i] = i, rk[i] = 0;
	for (int i = 1; i <= 15; i += 2)
		link(getfa(i), getfa(i + 1));
	for (int i = 1; i <= 13; i += 4)
		link(getfa(i), getfa(i + 2));
	link(getfa(1), getfa(5));
	link(getfa(11), getfa(13));
	link(getfa(1), getfa(10));
	getfa(2);
	getfa(9);
	for (int i = 1; i <= 16; i++)
		printf("%d %d\n", i, fa[i]);
	return 0;
}

