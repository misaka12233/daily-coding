#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;

void unsigned_divide(unsigned int first, unsigned int second, int *quotient, int *remainder);

#define shift_maxNum 2147483647
void divide(int first, int second, int *quotient, int *remainder)
{
    int flag1 = 0, flag2 = 0;
    if (first < 0) first = -first, flag1 ^= 1, flag2 ^= 1;
    if (second < 0) second = -second, flag2 ^= 1;
    unsigned_divide(first, second, quotient, remainder);
    // TODO
}

void unsigned_divide(unsigned int first, unsigned int second, int *quotient, int *remainder)
{
  *quotient = 0;
  *remainder = 0;
  if (second == 0) //判断除数是否为0
  {
    printf("illegal divisor!\n");
    return;
  }
  unsigned int temp = second;
  unsigned int shift = 1;
  while (temp <= first && temp <= shift_maxNum) //通过除数的移位操作来逼近被除数
  {
    temp <<= 1;
    if (temp <= first)
      shift <<= 1;
    else
    {
      *quotient += shift;
      temp >>= 1;
      first -= temp;
      shift = 1;
      temp = second;
    }
  }
  if (temp <= first && temp > shift_maxNum)
  {
    *quotient += shift;
    first -= temp;
  }
  *remainder = first;
}

int main()
{
	int x, y, p, q;
	while (scanf("%d%d", &x, &y))
	{
		divide(x, y, &p, &q);
		printf("%d %d\n", p, q);
	}
	return 0;
}

