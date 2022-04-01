#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("%d %d %d\n", max(0, max(b, c) - a + 1), max(0, max(a, c) - b + 1), max(0, max(a, b) - c + 1));
    }
    return 0;
}