#include <bits/stdc++.h>
using namespace std;
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
    out[--index] = '\n';
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