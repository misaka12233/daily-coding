#include <bits/stdc++.h>
using namespace std;
int a[70][70], n, m, s[70];
int main()
{
  int x = 0, y, t1, t2;
  while (x != -1)
  {
    cin >> x;
    s[++n] = x;
  }
  n--;
  cin >> m;
  while (m--)
  {
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
      if (s[i] == x)
        t1 = i;
    for (int i = 1; i <= n; i++)
      if (s[i] == y)
        t2 = i;
    a[t1][t2] = 1;
  }
  int tag = 1;
  for (int i = 1; i <= n; i++)
    if (a[i][i] == 0)
      tag = 0;
  if (tag)
    cout << "reflexive" << endl;
  tag = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j])
      {
        if (a[j][i] == 0)
          tag = 0;
      }
  if (tag)
    cout << "symmetric" << endl;
  tag = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (a[i][j] && a[j][k])
        {
          if (a[i][k] == 0)
            tag = 0;
        }
  if (tag)
    cout << "transitive" << endl;
  return 0;
}
