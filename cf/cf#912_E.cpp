#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n;
int cnt[2];
int typ[maxn];
bool vis[maxn];
queue<int> p[2];
bool printone(int t)
{
	while (!p[t].empty() && vis[p[t].front()]) p[t].pop();
	if (!p[t].empty())
	{
		printf("%d\n", p[t].front());
		p[t].pop();
		cnt[t]--;
		fflush(stdout);
		return true; 
	}
	while (!p[t ^ 1].empty() && vis[p[t ^ 1].front()]) p[t ^ 1].pop();
	if (!p[t ^ 1].empty())
	{
		printf("%d\n", p[t ^ 1].front());
		p[t ^ 1].pop();
		cnt[t ^ 1]--;
		fflush(stdout);
		return true; 
	}
	return false;
}
void sol()
{
	scanf("%d", &n);
	int sx, sy;
	scanf("%d%d", &sx, &sy);
	int st = (sx&1) ^ (sy&1);
	cnt[0] = cnt[1] = 0; 
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		typ[i] = (x&1) ^ (y&1);
		vis[i] = false;
		p[typ[i]].push(i);
		cnt[typ[i]]++;
	}
	if (p[st].size() >= p[st ^ 1].size())
	{
		puts("First");
		fflush(stdout);
		printone(st ^ 1); 
	}
	else
	{
		puts("Second");
		fflush(stdout);
	}
	int id;
	while (cnt[0] > 0 || cnt[1] > 0)
	{
		scanf("%d", &id);
		vis[id] = true;
		cnt[typ[id]]--;
		if (cnt[typ[id]] >= cnt[typ[id] ^ 1])
			printone(typ[id] ^ 1);
		else
			printone(typ[id]);
		fflush(stdout);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
	return 0;
}

