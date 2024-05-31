#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
set<string> s;
void test(set<string> &dst)
{
	dst.insert("abc");
}
int main()
{
	test(s);
	cout << *s.begin();
	return 0;
}

