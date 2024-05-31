#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int countSubstrings(string s) {
    string t;
    int n = s.length() * 2 + 1;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            t[i] = s[i / 2];
        else
            t[i] = '#';
    }
    vector<int> r;
    r.resize(n);
    int mx = 0, ans = 0;
    r[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (i > mx + r[mx] - 1)
        {
            r[i] = 1;
            while (0 <= i - r[i] && i + r[i] < n && t[i - r[i]] == t[i + r[i]])
                r[i]++;
            mx = i;
        }
        else
        {
            r[i] = min(r[2 * mx - i], mx + r[mx] - i);
            if (i + r[i] == mx + r[mx])
            {
                while (0 <= i - r[i] && i + r[i] < n && t[i - r[i]] == t[i + r[i]])
                    r[i]++;
                mx = i;
            }
        }
        ans += r[i] / 2;
    }
    return ans;
}
int main()
{
	string s;
	cin >> s;
	cout << countSubstrings(s);
	return 0;
}

