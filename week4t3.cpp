#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;
int n;
string tower[5], plate[15];
void movePlate(int x, int s, int t)
{
    if (x == 1)
    {
        cout << "Move " << plate[n - x + 1] << " from " << tower[s] << " to " << tower[t] << "." << endl;
        return;
    }
    int mid;
    for (int i = 1; i <= 3; i++)
    {
        if (i != s && i != t)
            mid = i;
    }
    movePlate(x - 1, s, mid);
    cout << "Move " << plate[n - x + 1] << " from " << tower[s] << " to " << tower[t] << "." << endl;
    movePlate(x - 1, mid, t);
    return;
}
int main()
{
    cin >> n;
    getline(cin, tower[0]);
    for (int i = 1; i <= 3; i++)
        getline(cin, tower[i]);
    for (int i = 1; i <= n; i++)
        getline(cin, plate[i]);
    movePlate(n, 1, 2);
    return 0;
}