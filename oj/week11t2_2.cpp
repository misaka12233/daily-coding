#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
const int inf = 0x7fffffff;
const double eps = 1e-6;
int a[maxn];
struct node{
    int val;
    double dis;
}b[maxn];
int n, k;
template<typename T> inline void fread(T &x)
{
    char ch = getchar();
    int f = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    x = 0;
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x = x * f;
}
inline void my_swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
inline void my_swap(node &x, node &y)
{
    node tmp = x;
    x = y;
    y = tmp;
}
int get_a_kth(int begin, int end, int rk)
{
    int t = rand() % (end - begin + 1) + begin;
    my_swap(a[t], a[begin]);
    int l = begin, r = end;
    while (l < r)
    {
        while (l < r && a[l] < a[r]) r--;
        if (l < r) my_swap(a[l], a[r]), l++;
        while (l < r && a[l] < a[r]) l++;
        if (l < r) my_swap(a[l], a[r]), r--;
    }
    if (l == rk) return a[l];
    if (l < rk) return get_a_kth(l + 1, end, rk);
    else return get_a_kth(begin, l - 1, rk);
}
bool cmp(int x, int y)
{
    if (b[x].dis - eps <= b[y].dis && b[y].dis <= b[x].dis + eps) return b[x].val > b[y].val;
    return b[x].dis < b[y].dis;
}
void get_b_kth(int begin, int end, int rk)
{
    int t = rand() % (end - begin + 1) + begin;
    my_swap(b[t], b[begin]);
    int l = begin, r = end;
    while (l < r)
    {
        while (l < r && cmp(l, r)) r--;
        if (l < r) my_swap(b[l], b[r]), l++;
        while (l < r && cmp(l, r)) l++;
        if (l < r) my_swap(b[l], b[r]), r--;
    }
    if (l == rk) return;
    if (l < rk) get_b_kth(l + 1, end, rk);
    else get_b_kth(begin, l - 1, rk);
}
double my_fabs(double x)
{
    if (x < 0) return -x;
    return x;
}
int main()
{
    fread(n);
    fread(k);
    for (int i = 1; i <= n; i++) fread(a[i]);
    double mid;
    if (n & 1) mid = get_a_kth(1, n, (n + 1) / 2);
    else
    {
        mid = get_a_kth(1, n, n / 2);
        int mn = inf;
        for (int i = n / 2 + 1; i <= n; i++)
        {
            if (a[i] >= mid && a[i] < mn)
                mn = a[i];
        }
        mid = (mid + mn) / 2.0;
    }
    for (int i = 1; i <= n; i++) 
    {
        b[i].val = a[i];
        b[i].dis = my_fabs(mid - a[i]);
    }
    long long ans = 0;
    get_b_kth(1, n, k);
    for (int i = 1; i <= k; i++) ans += b[i].val;
    printf("%lld\n", ans);
    return 0;
}