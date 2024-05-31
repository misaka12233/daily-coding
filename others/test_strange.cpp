#include<stdio.h>
int main()
{
	int x, a, b, c, d, y;
	scanf("abacd%d", &x);
	a = x / 1000;
	b = (x / 100) % 10;
	c = (x / 10) % 10;
	d = x % 10;
	
	y = d * 1000 + c * 100 + b * 10 + a;

	printf("the result is %d\n", y);
	return 0;
}

