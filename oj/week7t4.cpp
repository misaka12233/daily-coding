#include <bits/stdc++.h>
using namespace std;
namespace MyList
{
	const int MaxSize = 2e5 + 10;
	struct Item
	{
		int link[2];
	};
	struct list
	{
		Item item[MaxSize];
		int size;
		int cur;
		int idx;
		void init(int n)
		{
			size = 0;
			idx = 0;
			cur = 1;
			for (int i = 0; i < n; ++i)
				insert(), cur = idx;
			cur = 1;
			return;
		}
		void erase()
		{
			if (size == 0)
				return;
			item[item[cur].link[0]].link[1] = item[cur].link[1];
			item[item[cur].link[1]].link[0] = item[cur].link[0];
			cur = item[cur].link[0];
			size--;
			return;
		}
		void insert()
		{
			idx++;
			if (size == 0)
			{
				item[idx].link[0] = item[idx].link[1] = idx;
				cur = idx;
			}
			else
			{
				item[idx].link[0] = item[cur].link[0];
				item[idx].link[1] = cur;
				item[item[cur].link[0]].link[1] = idx;
				item[cur].link[0] = idx;
			}
			size++;
			return;
		}
		void move(int cnt, int dir)
		{
			if (size == 0)
				return;
			cnt = cnt % size;
			cnt = (cnt + size) % size;
			if (cnt * 2 > size)
			{
				cnt = size - cnt;
				dir = dir ^ 1;
			}
			for (int i = 1; i <= cnt; i++)
				cur = item[cur].link[dir];
			return;
		}
		int getCur()
		{
			return size ? cur : -1;
		}
	};
}
int main()
{
	MyList::list l;
	int op, x, n, m;
	cin >> n >> m;
	l.init(n);
	for (int i = 1; i <= m; i++)
	{
		cin >> op;
		switch (op)
		{
			case 0:
				l.erase();
				break;
			case 1:
				l.insert();
				break;
			case 2:
				cin >> x;
				l.move(x, 0);
				break;
			case 3:
				cin >> x;
				l.move(x, 1);
				break;
			default:
				cout << l.getCur() << endl;
				break;
		}
	}
	return 0;
}