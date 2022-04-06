#include <bits/stdc++.h>
using namespace std;
int func1(unsigned w)
{
    return (int) ((w << 24) >> 24);
}
int func2(unsigned w)
{
    return ((int)w << 24) >> 24;
}
int main()
{
    int w;
    scanf("%d", &w);
    printf("%d %d\n", func1(w), func2(w));
}