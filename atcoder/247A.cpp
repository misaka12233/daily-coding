#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int main()
{
    char s[5];
    scanf("%s", s);
    for (int i = 3; i >= 1; i--) s[i] = s[i - 1];
    s[0] = '0';
    printf("%s", s);
    return 0;
}