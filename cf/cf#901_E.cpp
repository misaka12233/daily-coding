#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[400000];
int calc(int *dst)
{
	int res = 0;
	for (int i = 0; i < 8; i++)
		res = res * 5 + dst[i];
	return res;
}
void divide(int s, int *dst)
{
	for (int i = 7; i >= 0; i--)
		dst[i] = s % 5, s /= 5;
}
bool check(int *dst)
{
	for (int i = 0; i < 8; i++)
		if (dst[i] != 4 && (i & 3) != dst[i])
			return false;
	return true;
}
queue<int> q;
void nxtInQueue(int *nxt, int now)
{
	int s = calc(nxt);
	if (dp[s] == -1)
	{
		dp[s] = dp[now] + 1;
		q.push(s);
	}
}
// a = a & b
// 010 -> 000
// 110 -> 100
void try1(int now, int *dst)
{
	int nxt[8];
	if (dst[0b010] != 4 || dst[0b110] != 4)
		return;
	if (dst[0b000] == 4 && dst[0b100] == 4)
		return;
	for (int i = 0; i < 8; i++)
		nxt[i] = dst[i];
	if (dst[0b000] != 4)
	{
		nxt[0b010] = dst[0b000];
		nxtInQueue(nxt, now);
		nxt[0b000] = 4;
		nxtInQueue(nxt, now);
		nxt[0b000] = dst[0b000];
		nxt[0b010] = dst[0b010];
	}
	if (dst[0b100] != 4)
	{
		nxt[0b110] = dst[0b100];
		nxtInQueue(nxt, now);
		nxt[0b100] = 4;
		nxtInQueue(nxt, now);
		nxt[0b100] = dst[0b100];
		nxt[0b110] = dst[0b110];
	}
	if (dst[0b000] != 4 && dst[0b100] != 4)
	{
		nxt[0b010] = dst[0b000];
		nxt[0b110] = dst[0b100];
		nxtInQueue(nxt, now);
		nxt[0b000] = 4;
		nxtInQueue(nxt, now);
		nxt[0b100] = 4;
		nxtInQueue(nxt, now);
		nxt[0b000] = dst[0b000];
		nxtInQueue(nxt, now);
	}
} 
// a = a | b
// 001 -> 011
// 101 -> 111
void try2(int now, int *dst)
{
	int nxt[8];
	if (dst[0b001] != 4 || dst[0b101] != 4)
		return;
	if (dst[0b011] == 4 && dst[0b111] == 4)
		return;
	for (int i = 0; i < 8; i++)
		nxt[i] = dst[i];
	if (dst[0b011] != 4)
	{
		nxt[0b001] = dst[0b011];
		nxtInQueue(nxt, now);
		nxt[0b011] = 4;
		nxtInQueue(nxt, now);
		nxt[0b011] = dst[0b011];
		nxt[0b001] = dst[0b001];
	}
	if (dst[0b111] != 4)
	{
		nxt[0b101] = dst[0b111];
		nxtInQueue(nxt, now);
		nxt[0b111] = 4;
		nxtInQueue(nxt, now);
		nxt[0b111] = dst[0b111];
		nxt[0b101] = dst[0b101];
	}
	if (dst[0b011] != 4 && dst[0b111] != 4)
	{
		nxt[0b001] = dst[0b011];
		nxt[0b101] = dst[0b111];
		nxtInQueue(nxt, now);
		nxt[0b011] = 4;
		nxtInQueue(nxt, now);
		nxt[0b111] = 4;
		nxtInQueue(nxt, now);
		nxt[0b011] = dst[0b011];
		nxtInQueue(nxt, now);
	}
} 
// b = a ^ b
// 010 -> 011
// 011 -> 010
// 110 -> 111
// 111 -> 110
void try3(int now, int *dst)
{
	int nxt[8];
	for (int i = 0; i < 8; i++)
		nxt[i] = dst[i];
	swap(nxt[0b010], nxt[0b011]);
	swap(nxt[0b110], nxt[0b111]);
	nxtInQueue(nxt, now);
} 
// b = b ^ m
// 100 -> 101
// 101 -> 100
// 110 -> 111
// 111 -> 110
void try4(int now, int *dst)
{
	int nxt[8];
	for (int i = 0; i < 8; i++)
		nxt[i] = dst[i];
	swap(nxt[0b100], nxt[0b101]);
	swap(nxt[0b110], nxt[0b111]);
	nxtInQueue(nxt, now);
} 
void bfs()
{
	memset(dp, -1, sizeof(dp));
	int n = 1;
	for (int i = 0; i < 8; i++)
		n = n * 5;
	int dst[8];
	for (int i = 0; i < n; i++)
	{
		divide(i, dst);
		if (check(dst))
		{
			dp[i] = 0;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		divide(s, dst);
		try1(s, dst);
		try2(s, dst);
		try3(s, dst);
		try4(s, dst);
	}
}
int sol()
{
	int dst[8];
	int a, b, c, d, m;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &m);
	for (int i = 0; i < 8; i++)
		dst[i] = 4;
	for (int i = 0; i < 30; i++)
	{
		int x = 0, y = 0;
		if (a & (1 << i)) x += 2;
		if (b & (1 << i)) x += 1;
		if (m & (1 << i)) x += 4;
		if (c & (1 << i)) y += 2;
		if (d & (1 << i)) y += 1;
		if (dst[x] != 4 && dst[x] != y)
			return -1;
		dst[x] = y;
	}
	return dp[calc(dst)];
}
int main()
{
	int T;
	bfs();
	scanf("%d", &T);
	while (T--) 
		printf("%d\n", sol()); 
	return 0;
}

