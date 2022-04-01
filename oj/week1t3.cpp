#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        double a, t;
        scanf("%lf%lf", &a, &t);
        a = fabs(a);
        t = fabs(t);
        printf("%.1lf\n", a * t * t / 2.0);
    }
    return 0;
}