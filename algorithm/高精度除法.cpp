#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
char s[maxn];
int n, m;
int a[maxn], b[maxn];
int r[maxn] = {0};
int res[maxn] = {0};
int lst[maxn] = {0};
int ans[maxn] = {0};
void print(int *x)
{
    int fir = 0;
    for (int i = 1; i <= n; i++)
        if (fir || x[i])
            putchar(x[i] + '0'), fir = 1;
    putchar('\n');
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
    scanf("%s", s + 1);
    m = strlen(s + 1);
    for (int i = n - m + 1; i <= n; i++) b[i] = s[i - (n - m)] - '0';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
            r[j] = r[j + 1];
        r[n] = a[i];
        // 余数整体左移一位并加上当前处理的最低位
        memset(res, 0, sizeof(res));
        memset(lst, 0, sizeof(lst));
        int j;
        for (j = 1; j <= 9; j++)
        {
            int c = 0;
            for (int k = n; k >= 0; k--)
            {
                lst[k] = res[k];
                int tmp = res[k] + b[k] + c;
                c = tmp / 10;
                res[k] = tmp % 10;
            }
            // res记录当前试商结果，与余数进行比较，lst记录真正的商对应的数值
            for (int k = 0; k <= n; k++)
            {
                if (res[k] > r[k])
                    goto BREAK;
                if (res[k] < r[k])
                    goto CONTINUE;
            }
            CONTINUE: continue;
            BREAK: break;
            // res > r 时break，否则继续循环
        }
        // 当前位商为j-1，余数r减去lst
        ans[i] = j - 1;
        //printf("%d: %d\n", i, ans[i]);
        int c = 0;
        for (int k = n; k >= 0; k--)
        {
            int tmp = r[k] - lst[k] - c;
            if (tmp < 0) tmp += 10, c = 1;
            else c = 0;
            r[k] = tmp % 10;
        }
    }
    print(ans);
    print(r);
}