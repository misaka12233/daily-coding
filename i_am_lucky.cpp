#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main()
{
	srand(time(0));
	int a = rand(), b = rand(), c = rand();
	if (a & 1)
	puts("reflexive");
	if (b & 1)
	puts("symmetric");
	if (c & 1)
	puts("transitive");
	return 0;
}

