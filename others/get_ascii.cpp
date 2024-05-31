#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
char s[] = "Hello,world\n";
int main()
{
	int l = strlen(s);
	for (int i = 0; i <= l; i++) 
		printf("%02x", s[i]);
	return 0;
}

