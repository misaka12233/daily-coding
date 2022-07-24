#include <bits/stdc++.h>
using namespace std;
void Print(int n)
{
    if (n == 1)
    {
        printf("1 ");
        return;
    }
    Print(n - 1);
    printf("%d ", n);
    Print(n - 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    Print(n);
    return 0;
}