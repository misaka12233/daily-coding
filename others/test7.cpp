#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main()
{
	char s[] = {"JTH"};
	s[0] = (s[0] - 'A' + 114514) % 26 + 'A';
	s[1] = (s[1] - 'A' + 114514) % 26 + 'A';
	s[2] = (s[2] - 'A' + 114514) % 26 + 'A';
	printf("%s", s);
	return 0;
}

