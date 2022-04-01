#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[50], b[50], sum[2000010];
const int inf = 0x3f3f3f3f;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i + 1])
                cnt++;
            else
                cnt = 1;
            if (cnt >= n / 2)
                break;
        }
        if (cnt >= n / 2)
        {
            puts("-1");
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n / 2 + 1; i++)
        {
            for (int j = i + 1; j <= n; j++)
                b[j] = a[j] - a[i];
            memset(sum, 0, sizeof(sum));
            int tmp = 1;
            for (int j = i + 1; j <= n; j++)
            {
                if (b[j] == 0)
                {
                    tmp++;
                    continue;
                }
                for (int l = 1; l <= sqrt(b[j]); l++)
                {
                    if (b[j] % l == 0)
                    {
                        sum[l]++;
                        if (sum[l] >= n / 2 - tmp)
                            ans = max(ans, l);
                        if (l * l != b[j])
                        {
                            sum[b[j] / l]++;
                            if (sum[b[j] / l] >= n / 2 - tmp)
                               ans = max(ans, b[j] / l);
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
