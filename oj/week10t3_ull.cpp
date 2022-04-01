#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull totdigit = 128;
const ull I = 1;
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
ull x, y;
int n;
int main()
{
	fread(n);
	for(int i = 1; i <= n; i++)
	{
		int op;
		fread(op);
		if (op == 1)
		{
			ull num;
			fread(num);
			num = (num % totdigit + totdigit) % totdigit;
			ull tmp1, tmp2;
			if (num == 0)
				continue;
			if (num == 64)
			{
				swap(x, y);
				continue;
			} 
			if (num > 64)
			{
				tmp1 = (x << (128 - num)) + (y >> (num - 64));
				tmp2 = (y << (128 - num)) + (x >> (num - 64));
			}
			else
			{
				tmp1 = (y << (64 - num)) + (x >> num);
				tmp2 = (x << (64 - num)) + (y >> num);
			}
			x = tmp1;
			y = tmp2;
		}
		else if (op == 2)
			printf("%X\n", (unsigned short) x);
		else if (op == 3)
		{
			ull l, r, tmp1, tmp2;
			fread(l), fread(r);
			if (l <= 63 && 63 < r)
			{
				tmp1 = ((I << 63) - (I << l)) ^ (I << 63);
				tmp2 = ((I << (r - 64)) - I) ^ (I << (r - 64));
			}
			else if (r <= 63)
			{
				tmp1 = ((I << r) - (I << l)) ^ (I << r);
				tmp2 = 0;
			}
			else if (l > 63)
			{
				tmp1 = 0;
				tmp2 = ((I << (r - 64)) - (I << (l - 64))) ^ (I << (r - 64));
			}
			x ^= tmp1;
			y ^= tmp2;
		}
	}
	return 0;
}
