#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1000000 + 5;

int n, k;
int a[maxn];
int max_ans_x, max_ans_y;
int sufMin[maxn];
int min_ans_x, min_ans_y;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    int mx = a[n], pos = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] + mx >= k)
        {
            pos = i;
            break;
        }
        mx = max(mx, a[i]);
    }
    int have_1 = 0;
    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1) have_1 = i;
        if (have_1 && a[i] == k - 1) 
            now = i;
    }
    if (now > pos)
    {
        max_ans_x = have_1;
        max_ans_y = now;
    }
    else if (pos != 0)
    {
        max_ans_x = pos;
        for (int i = n; i > pos; i--)
        {
            if (a[i] + a[pos] >= k)
            {
                max_ans_y =i;
                break;
            }
        }
    }
    if (max_ans_x == 0)
    {
        max_ans_x = 1;
        max_ans_y = 2;
    }
    bool pre_0 = true;
    for (int i = 1; i <= n; i++)
    {
        if (i == max_ans_x)
        {
            if (a[max_ans_x] + a[max_ans_y] >= k)
                printf("1 "), pre_0 = false;
        }
        else if (i == max_ans_y)
        {
            if ((a[max_ans_x] + a[max_ans_y]) % k != 0 || !pre_0)
                printf("%d ", (a[max_ans_x] + a[max_ans_y]) % k), pre_0 = false;
        }
        else if (a[i] != 0 || !pre_0)
            printf("%d ", a[i]), pre_0 = false;
    }
    puts("");
    sufMin[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
        sufMin[i] = min(sufMin[i + 1], a[i]);
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] > a[i + 1] && a[i] + sufMin[i + 2] < k)
        {
            min_ans_x = i;
            for (int j = n; j > i + 1; j--)
            {
                if (a[i] + a[j] < k)
                {
                    min_ans_y = j;
                    break;
                }
            }
            break;
        }
    }
    if (min_ans_x == 0)
    {
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] + sufMin[i + 1] < k)
            {
                min_ans_x = i;
                for (int j = n; j > i; j--)
                {
                    if (a[i] + a[j] < k)
                    {
                        min_ans_y = j;
                        break;
                    }
                }
                break;
            }
        }
        if (min_ans_x == 0)
        {
            min_ans_x = 1;
            min_ans_y = 2;
        }
    }
    pre_0 = true;
    for (int i = 1; i <= n; i++)
    {
        if (i == min_ans_x)
        {
            if (a[min_ans_x] + a[min_ans_y] >= k)
                printf("1 "), pre_0 = false;
        }
        else if (i == min_ans_y)
        {
            if ((a[min_ans_x] + a[min_ans_y]) % k != 0 || !pre_0)
                printf("%d ", (a[min_ans_x] + a[min_ans_y]) % k), pre_0 = false;
        }
        else if (a[i] != 0 || !pre_0)
            printf("%d ", a[i]), pre_0 = false;
    }
    return 0;
}
