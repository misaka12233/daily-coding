#include<bits/stdc++.h>
using namespace std;

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

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
const int maxm = 20000 + 10;
int n, m;
int w[maxn], v[maxn], cnt[maxn];
int dp[maxm];
deque<int> q;
int calc(int x, int i)
{
	return dp[x] - x / w[i] * v[i];
}
int main()
{
	read(m), read(n);
	for (int i = 1; i <= n; i++)
		read(v[i]), read(w[i]), read(cnt[i]);
	for (int i = 1; i <= m; i++)
		dp[i] = -inf;
	for (int i = 1; i <= n; i++)
	{
		for (int now = 0; now < w[i]; now++)
		{
			q.clear();
			for (int j = 0; j < cnt[i] && m - now >= j * w[i]; j++)
			{
				int k = m - now - j * w[i];
				while (!q.empty() && calc(q.back(), i) <= calc(k, i)) 
					q.pop_back();
				q.push_back(k);
			}
			for (int j = m - now; j >= 0; j -= w[i])
			{
				int k = j - cnt[i] * w[i];
				if (k >= 0)
				{
					while (!q.empty() && calc(q.back(), i) <= calc(k, i)) 
						q.pop_back();
					q.push_back(k);
				}
				while (!q.empty() && j < q.front()) 
					q.pop_front();
				k = q.front();
				if (dp[k] == -inf)
					dp[j] = -inf;
				else
					dp[j] = dp[k] + (j - k) / w[i] * v[i];
			}
		}
	}
	if (dp[m] != -inf) write(dp[m]);
	else puts("-1");
	return 0;
}

