#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("MAX_CUT.out", "r", stdin);
	system("datamaker.exe");
	system("MAX_CUT.exe");
	int ans, res;
	scanf("%d%d", &ans, &res);
	printf("%d %d %f\n", ans, res, (double)res / ans);
	return 0;
}

