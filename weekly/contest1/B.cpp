#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n, m = 720;
int y[maxn];
bool vis[maxn];
void update(int ay, int by)
{
	if (abs(by - ay) == 360)
	{
		for (int i = 0; i < m; i++)
			vis[i] = true;
	}
	else if (abs(by - ay) > 360)
	{
		for (int i = 0; i <= min(ay, by); i++)
			vis[i] = true;
		for (int i = max(ay, by); i < m; i++)
			vis[i] = true;
	}
	else
		for (int i = min(ay, by); i <= max(ay, by); i++)
			vis[i] = true;
}
int main()
{
	scanf("%d", &n);
	int x;
	scanf("%d%d", &x, &y[1]);
	y[1] = (y[1] + 180) * 2;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d%d", &x, y + i);
		y[i] = (y[i] + 180) * 2;
		update(y[i - 1], y[i]);
	}
	update(y[n], y[1]);
	int t = 0;
	for (int i = 0; i < m; i++)
	{
		if (!vis[i])
		{
			printf("no %.1f\n", 1.0 * (i - 360) / 2);
			return 0;
		}
	}
	printf("yes\n");
	return 0;
}

