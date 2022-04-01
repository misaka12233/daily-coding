#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (b * b - 4 * a * c < 0)
        puts("No Solution");
    else
    {
        double ans1 = -b / (2 * a), ans2 = sqrt(b * b - 4 * a * c) / (2 * a);
        printf("%.2lf %.2lf \n", ans1 - ans2, ans1 + ans2);
    }
    return 0;
}
