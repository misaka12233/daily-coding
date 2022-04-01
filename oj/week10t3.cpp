#include<bits/stdc++.h>
using namespace std;
typedef __uint128_t ull;
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
ull x;
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
			x = (x << (128 * I - num)) + (x >> num);
		}
		else if (op == 2)
			printf("%X\n", (unsigned short) x);
		else if (op == 3)
		{
			ull l, r;
			fread(l), fread(r);
			ull tmp = ((I << r) - (I << l)) ^ (I << r);
			x ^= tmp;
		}
	}
	return 0;
}

