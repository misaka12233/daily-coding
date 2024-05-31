#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int a[maxn];
int p2[31], in[31], out[31], tot;
bool check(int x, int s)
{
	if (x == s)
	{
		tot++;
		return true;
	}
	int t = abs(x - s), l = 0, r = 0;
	while (t % 2 == 0)
	{
		t >>= 1;
		l++, r++;
	}
	while (t & 1)
	{
		t >>= 1;
		r++;
	}
	if (t != 0) return false;
	if (x > s)
	{
		out[r]++;
		in[l]++;
	}
	else
	{
		out[l]++;
		in[r]++;
	}
	return true;
}
bool sol()
{
	int n;
	scanf("%d", &n);
	p2[0] = 1;
	tot = in[0] = out[0] = 0;
	for (int i = 1; i <= 30; i++)
	{
		p2[i] = p2[i - 1] * 2;
		in[i] = out[i] = 0;
	}
	long long s = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		s = s + a[i];
	}
	if (s % n != 0) return false;
	s = s / n;
	for (int i = 1; i <= n; i++)
	{
		if (!check(a[i], s))
			return false;
	}
	bool empt = true;
	for (int i = 0; i <= 30; i++)
	{
		if (in[i] != out[i])
			return false;
		if (in[i] != 0)
			empt = false;
	}
	if (tot == 1) return !empt;
	else return true;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) 
	{
		if (sol()) puts("Yes");
		else puts("No");
	} 
	return 0;
}

