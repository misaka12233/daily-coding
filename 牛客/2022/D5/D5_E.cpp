#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n, t;
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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

struct Node {
    ll p, q;
    Node(ll _p=0, ll _q=1) {
        ll d = gcd(_p, _q);
        p = _p/d, q = _q/d;
    }
    Node operator + (const Node &B) const {
        return Node(p*B.q + B.p*q, q*B.q);
    }
    bool operator < (const Node &B) const {
        return p*B.q < B.p*q;
    }
    bool operator > (const Node &B) const {
        return p*B.q > B.p*q;
    }
};
Node max(Node a, Node b)
{
	if (a < b) return b;
	else return a;
}
Node stz[maxn][maxn][10], stf[maxn][maxn][10];
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		read(t);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				ll x, y;
				read(x), read(y);
				stz[i][j][0] = stf[i][j][0] = Node(x, y);
			}
		}
		for (int k = 1, len = 1; k < 10; k++, len <<= 1)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= i; j++)
				{
					if (i >= 2 * len && j + 2 * len - 1 <= i)
					stz[i][j][k] = max(max(stz[i][j][k - 1], stz[i][j + len][k - 1]), 
									   max(stz[i - len][j][k - 1], stf[i - len][j + len][k - 1]));
					if (i + 2 * len - 1 <= n && j >= 2 * len)
					stf[i][j][k] = max(max(stf[i][j][k - 1], stf[i][j - len][k - 1]), 
									   max(stf[i + len][j][k - 1], stz[i + len][j - len][k - 1]));
				}
			}
		}
		int l = log(t) / log(2), len = 1 << l;
		Node ans = Node(0, 1);
		for (int i = t; i <= n; i++)
		{
			for (int j = 1; j + t - 1 <= i; j++)
			{
				ans = ans + max(max(stz[i][j][l], stz[i][j + len][l]), 
								max(stz[i - len][j][l], stf[i + len][j + len][l]));
			}
		}
		printf("%lld/%lld\n", ans.p, ans.q);
	}
	return 0;
}
/*
3 2
1/3
5/28 11/37
14/31 17/29 7/47
*/
