#include <bits/stdc++.h>
using namespace std;

struct Job {
	int pos, priority;
};

int main() {
	int Q, n, m, priority;
	cin >> Q;
	
	while (Q--) {
		queue<Job> q;
		priority_queue<int> pq;
		
		cin >> n >> m;
		
		for (int i = 0; i < n; i++) {
			cin >> priority;
			q.push((Job) {i, priority});
			pq.push(priority);
		}
		
		int count = 0;
		
		while (!pq.empty()) {
			if (pq.top() == q.front().priority) {
				count++;
				
				if (q.front().pos == m) {
					break;
				}
				
				q.pop();
				pq.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		
		cout << count << endl;
	}
	return 0;
}