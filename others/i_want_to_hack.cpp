#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1e6 + 3;
int n, k, a[N], b[N], mn[N], r1;
bool del[N];
int read()
{
    char c = getchar();
    int x = 0;
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c))
        x = (x << 3) + (x << 1) + c - 48, c = getchar();
    return x;
}
void Print(int x)
{
    if (x > 9)
        Print(x / 10);
    putchar(x % 10 + 48);
}
void sol1()
{
    if (a[n] == k - 1 && r1)
    {
        a[n] = 0;
        return;
    }
    int mx = a[n];
    for (int i = n - 1; i; --i)
    {
        if (a[i] + mx >= k)
            for (int j = n; j > i; --j)
                if (a[i] + a[j] >= k)
                {
                    a[j] += a[i] - k;
                    a[i] = 1;
                    return;
                }
        if (a[i] > mx)
            mx = a[i];
    }
    a[2] += a[1];
    del[1] = 1;
}
void sol2()
{
    for (int i = 1; i < n - 1; ++i)
        if (b[i] > b[i + 1] && b[i] + mn[i + 2] < k)
            for (int j = n; j > i + 1; --j)
                if (b[i] + b[j] < k)
                {
                    b[j] += b[i];
                    del[i] = 1;
                    return;
                }
    for (int i = n - 1; i; --i)
        if (b[i] + mn[i + 1] < k)
            for (int j = n; j > i; --j)
                if (b[i] + b[j] < k)
                {
                    b[j] += b[i];
                    del[i] = 1;
                    return;
                }
    if (b[1] > 1)
    {
        b[2] += b[1] - k;
        b[1] = 1;
        return;
    }
    b[2] = 0;
}
int main()
{
    n = read();
    k = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = b[i] = read();
        if (a[i] == 1)
            r1 = i;
    }
    sol1();
    for (int i = 1; i <= n; ++i)
        if (!del[i])
            Print(a[i]), putchar(' ');
    putchar('\n');
    del[1] = 0;
    mn[n] = b[n];
    for (int i = n - 1; i; --i)
        mn[i] = min(mn[i + 1], b[i]);
    sol2();
    for (int i = 1; i <= n; ++i)
    {
        if (!b[i])
            del[i] = 1;
        if (!del[i])
            break;
    }
    for (int i = 1; i <= n; ++i)
        if (!del[i])
            Print(b[i]), putchar(' ');
    return 0;
}
