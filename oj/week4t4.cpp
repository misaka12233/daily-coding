#include <bits/stdc++.h>
using namespace std;
long long ans1;
int len1, len2;
double ans2, p[5];
char ans3[100010], ans4[100010], s[100010];
int main()
{
    scanf("%s", s);
    int l = strlen(s), cnt = 0;
    double x = 0;
    p[0] = 1.0;
    bool type = true;
    for (int i = 1; i <= 3; i++)
        p[i] = p[i - 1] * 0.1;
    for (int i = 0; i < l; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (type)
                x = x * 10 + s[i] - '0';
            else
                x = x + (double(s[i] - '0')) * p[cnt++];
        }
        if (s[i] == '.')
            cnt++, type = false;
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (type)
                ans1 += int(x + 0.1);
            else
                ans2 += x;
            x = cnt = 0;
            type = true;
            ans3[len1++] = s[i] - 'A' + 'a';
        }
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (type)
                ans1 += int(x + 0.1);
            else
                ans2 += x;
            x = cnt = 0;
            type = true;
            ans4[len2++] = s[i] - 'a' + 'A';
        }
    }
    if (type)
        ans1 += int(x + 0.1);
    else
        ans2 += x;
    printf("%lld\n%.2lf\n%s\n%s\n", ans1, ans2, ans3, ans4);
    return 0;
}
