#include<bits/stdc++.h>
using namespace std;
const int K = 300;
const int R = 350;
const int N = 1000000;
int vis[N + 1];
int sol()
{
	int x, mx;
	scanf("%d", &x);
	mx = x;
	for (int i = 1; i <= K; i++)
	{
		printf("+ %d\n", rand() * rand() % N);
		fflush(stdout);
		scanf("%d", &x);
		mx = max(mx, x);
	}
	for (int i = 1; i <= N; i++)
		vis[i] = -1;
	vis[x] = 0;
	for (int i = 1; i < R; i++)
	{
		printf("+ 1\n");
		fflush(stdout);
		scanf("%d", &x);
		if (vis[x] != -1)
			return i - vis[x];
		vis[x] = i;
	}
	for (int i = 1; i <= R; i++)
	{
		printf("+ %d\n", (i == 1) ? mx : R);
		fflush(stdout);
		scanf("%d", &x);
		if (vis[x] != -1)
			return mx + (i - 1) * R + (R - 1) - vis[x];
		vis[x] = i;
	}
	return 0;
}
int main()
{
	printf("! %d\n", sol());
	return 0;
}

