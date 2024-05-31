#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int a[maxn];
int cnt[31], up[31], down[31];
bool check(int x, int s)
{
	if (x == s)
		return true;
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
		if (r - l == 1)
			down[l]++;
		else
		{
			cnt[r]--;
			cnt[l]++;
		}
	}
	else
	{
		if (r - l == 1)
			up[l]++;
		else
		{
			cnt[l]--;
			cnt[r]++;
		}
	}
	return true;
}
bool sol()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= 30; i++)
		cnt[i] = up[i] = down[i] = 0;
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
	for (int i = 0; i <= 30; i++)
	{
		if (cnt[i])
		{
			if (up[i] + down[i] < abs(cnt[i])) return false;
			if ((up[i] + down[i] + cnt[i]) & 1) return false;
			while (abs(cnt[i]) > 0 && up[i] > 0)
			{
				if (cnt[i] > 0)
				{
					cnt[i]--;
					cnt[i + 1]++;
				}
				else
					cnt[i]++;
				up[i]--;
			}
			while (abs(cnt[i]) > 0 && down[i] > 0)
			{
				if (cnt[i] > 0)
					cnt[i]--;
				else
				{
					cnt[i]++;
					cnt[i + 1]--;
				}
				down[i]--;
			}
		}
		while (up[i] > 0 && down[i] > 0)
		{
			up[i]--;
			down[i]--;
		}
		while (up[i] > 0)
		{
			cnt[i + 1]++;
			up[i] -= 2;
		}
		while (down[i] > 0)
		{
			cnt[i + 1]--;
			down[i] -= 2;
		}
	}
	return true;
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

