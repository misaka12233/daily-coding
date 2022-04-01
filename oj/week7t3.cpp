#include <bits/stdc++.h>
using namespace std;
namespace MyQueue {
	const int MaxSize = 5e5 + 10;
	struct queue {
		int item[MaxSize], limit, head, tail; 
		void init(int limit) 
        {
			for (int i = 0; i < limit; i++)
                item[i] = 0;
            head = 0;
            tail = 0; 
            this->limit = limit;
		}
		bool empty() 
        {
			return head == tail;
		}
		bool full() 
        {
			return tail - head == limit;
		}
		void insert(int value) 
        {
			item[tail % limit] = value;
            tail++;
		}
		int pop() 
        {
			int t = item[head % limit];
            head++;
            return t;
		}

	};
}
int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	using MyQueue::queue;
	queue q;
	q.init(n);
	while (m--) {
		int op, x;
		cin >> op;
		if (op == 1) {
			cin >> x;
			if (!q.full()) {
				q.insert(x);
			}
		} else {
			if (!q.empty()) {
				cout << q.pop() << endl;
			}
		}
	}
	return 0;
}