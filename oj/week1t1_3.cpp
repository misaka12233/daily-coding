#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;

template <typename type>
void read(type &a) 
{
    int t, f = 0;
    while (!isdigit(t = getchar())) 
        f |= t == '-';
    a = t - '0';
    while ( isdigit(t = getchar())) 
    {
        a *= 10;
        a += t - '0';
    }
    a = f ? -a : a;
}
template <typename type>
void write(type a) 
{
    char out[35];
    int index = 35;
    out[--index] = 0;
    out[--index] = '\n';
    if (a < 0) 
    {
        putchar('-');
        a = -a;
    }
    if (a) 
    {
        do 
        {
            out[--index] = a % 10 + '0';
        } 
        while(a /= 10);
    } 
    else
        out[--index] = '0';
    do 
    {
        putchar(out[index]);
    } 
    while(out[++index]);
}

const int maxn = 500 + 10;
int n, m;
ll ans;
ll dp[maxn][maxn];
ll a[maxn];

int main()
{
	read(n), read(m);
	while (n--)
	{
		for (int i = 1; i <= m; i++)
			read(a[i]), a[i] = a[i] * a[i] * a[i];
		ll res = 0;
		for (int len = 1; len <= m; len++)
		{
			for (int l = 0; l <= len; l++)
			{
				int r = m + l - len + 1;
				if (l == 0) dp[l][r] = dp[l][r + 1] + a[r] * len * len;
				else if (r == m + 1) dp[l][r] = dp[l - 1][r] + a[l] * len * len;
				else dp[l][r] = max(dp[l - 1][r] + a[l] * len * len, dp[l][r + 1] + a[r] * len * len);
				res = max(res, dp[l][r]);
			}
		}
		ans += res;
	}
	write(ans);
	return 0;
}

