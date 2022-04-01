#include <bits/stdc++.h>
using namespace std;
const int maxn = 9 + 5;
const double eps = 1e-8;
double A[maxn][maxn * 2];
int n;
void minusL(int x, int y, int k)
{
    if (fabs(A[x][k]) < eps)
        return;
    double mul = A[y][k] / A[x][k];
    for (int i = 1; i <= 2 * n; i++)
        A[y][i] -= A[x][i] * mul;
    return;
}
bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (fabs(A[i][i]) < eps)
                return false;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) 
                continue;
            else if(fabs(A[i][j]) > eps)
                return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%lf", &A[i][j]);
    for (int i = 1; i <= n; i++)
        A[i][i + n] = 1;
    for (int i = 1; i < n; i++)
    {
        if (fabs(A[i][i]) < eps)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (fabs(A[j][i]) > eps)
                {
                    for (int l = 1; l <= 2 * n; l++)
                        A[i][l] += A[j][l];
                    break;
                }
            }
        }
        for (int j = i + 1; j <= n; j++)
            minusL(i, j, i);
    }
    for (int i = n; i > 1; i--)
        for (int j = i - 1; j >= 1; j--)
            minusL(i, j, i);
    if (check())
    {
        for (int i = 1; i <= n; i++)
        {
            double mul = A[i][i];
            for (int j = 1; j <= 2 * n; j++)
                A[i][j] /= mul;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                printf("%.3lf ", A[i][j + n]);
            puts("");
        }
    }
    else
        puts("No Solution");
    return 0;
}