#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1000000 + 10;
const int inf = 0x3f3f3f3f;
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
priority_queue <pii> q;
int s[35][maxn];
int now[35];
int k, m;
int main()
{
    read(k);
    read(m);
    for (int i = 1; i <= k; i++)
    {
        int mn = inf;
        read(s[i][0]);
        for (int j = 1; j <= s[i][0]; j++)
            read(s[i][j]), mn = min(mn, s[i][j]);
        if (mn != s[i][1])
        {
            for (int j = 1; j <= s[i][0] / 2; j++)
                swap(s[i][j], s[i][s[i][0] - j + 1]);
        }
        now[i] = 1;
        q.push(pii(-s[i][1], i));
    }
    for (int i = 1; i <= m; i++)
    {
        pii x = q.top();
        q.pop();
        write(-x.first);
        now[x.second]++;
        if (now[x.second] > s[x.second][0]) continue;
        q.push(pii(-s[x.second][now[x.second]], x.second));
    }
}