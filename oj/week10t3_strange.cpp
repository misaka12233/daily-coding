#include<bits/stdc++.h>
using namespace std;
const int maxn = 128 + 10;
int pow2[maxn];
int c[maxn];
int lowbit(int x)
{
	return x & (-x);
}
void update(int pos, int val)
{
	for (int x = pos; x <= 128; x += lowbit(x))
		c[x] += val;
}
int query(int pos)
{
	int ans = 0;
	for (int x = pos; x; x -= lowbit(x))
		ans += c[x];
	return ans & 1;
}

const int totdigit = 128;
template <typename T>
void fread(T &a)
{
    char c = getchar(), f = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-') 
			f = -1;
		c = getchar();
	}
    a = 0;
    while (c >= '0' && c <= '9') 
	{
        a *= 10;
        a += c - '0';
        c = getchar();
    }
    a *= f;
}
int n;
int head;
int main()
{
	fread(n);
	pow2[0] = 1;
	for (int i = 1; i <= 16; i++)
		pow2[i] = pow2[i - 1] << 1; 
	for (int i = 1; i <= n; i++)
	{
		int op;
		fread(op);
		if (op == 1)
		{
			int num;
			fread(num);
			num = (num % totdigit + totdigit) % totdigit;
			head = (head + num) % totdigit;
		}
		else if (op == 2)
		{
			int ans = 0;
			for (int i = 0; i < 16; i++)
				ans += query((head + i) % totdigit + 1) * pow2[i];
			printf("%X\n", ans);
		}
		else if (op == 3)
		{
			int l, r;
			fread(l), fread(r);
			l = (head + l) % totdigit;
			r = (head + r) % totdigit;
			if (l > r)
			{
				update(l + 1, 1);
				update(1, 1);
				update(r + 2, -1);
			}
			else
			{
				update(l + 1, 1);
				update(r + 2, -1);
			}
		}
	}
	return 0;
}

