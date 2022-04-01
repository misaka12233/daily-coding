#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    printf("%d %d\n", a, b);
    return 0;
}