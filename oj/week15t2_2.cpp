#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
template <typename type>
void read(type &a) 
{
    int t, f = 0;
    while (!isdigit(t = getchar())) 
        f |= t == '-';
    a = t - '0';
    while ( isdigit(t = getchar())) 
    {
        a *= 10;
        a += t - '0';
    }
    a = f ? -a : a;
}
template <typename type>
void write(type a) 
{
    char out[35];
    int index = 35;
    out[--index] = 0;
    out[--index] = ' ';
    if (a < 0) 
    {
        putchar('-');
        a = -a;
    }
    if (a) 
    {
        do 
        {
            out[--index] = a % 10 + '0';
        } 
        while(a /= 10);
    } 
    else
        out[--index] = '0';
    do 
    {
        putchar(out[index]);
    } 
    while(out[++index]);
}
int n;
int rtFir[maxn], rkInMid[maxn];
void Print(int now, int l, int r)
{
    if (l == r)
    {
        write(rtFir[now]);
        return;
    }
    if (l < rkInMid[rtFir[now]])
        Print(now + 1, l, rkInMid[rtFir[now]] - 1);
    if (rkInMid[rtFir[now]] < r)
        Print(now + rkInMid[rtFir[now]] - l + 1, rkInMid[rtFir[now]] + 1, r);
    write(rtFir[now]);
}
int main()
{
    read(n);
    for (int i = 1; i <= n; i++) read(rtFir[i]);
    int x;
    for (int i = 1; i <= n; i++)
    {
        read(x);
        rkInMid[x] = i;
    }
    Print(1, 1, n);
    return 0;
}