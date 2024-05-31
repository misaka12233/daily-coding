#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1000000000000000000ll;
 
ll sol() {
  ll x; scanf("%lld", &x);
  ll rmn = 0;
  while (x <= INF) {
    ll l = x, r = min(x +rmn, INF);
    ll k = ceil(sqrt(l));
    if (k * k <= r) return k;
    x = x * 10;
    rmn = rmn * 10 + 9;
  }
  return -1;
}
 
int main() {
  int _; scanf("%d", &_); while (_--)
    printf("%lld\n", sol());
  return 0;
}
