#include <bits/stdc++.h>
using namespace std;
const double smallValue = 1e-9;
int T;
double a, b, c;
double f(double x)
{
    return a * x * x + b * x + c;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        double x0, x1, y0, y1, y2;
        scanf("%lf%lf%lf", &a, &b, &c);
        scanf("%lf%lf%lf%lf%lf", &x0, &x1, &y0, &y1, &y2);
        if (fabs(f(x0) - y0) < smallValue || fabs(f(x1) - y0) < smallValue)
        {
            puts("No");
            continue;
        }
        else
        {
            if (f(x0) > y0 && f(x1) < y0)
            {
                puts("Yes");
                continue;
            }
            else
            {
                if (f(x1) > y0 && (f(x1) < y2 || fabs(f(x1) - y2) < smallValue))
                {
                    if (fabs(f(2.0 * x1 - x0) - y0) < smallValue)
                    {
                        puts("No");
                        continue;
                    }
                    else
                    {
                        if (f(2.0 * x1 - x0) < y0)
                        {
                            puts("Yes");
                            continue;
                        }
                        else
                        {
                            puts("No");
                            continue;
                        }
                    }
                }
                else
                {
                    puts("No");
                    continue;
                }
            }
        }
    }
    return 0;
}