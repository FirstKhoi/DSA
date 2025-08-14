#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3825/problems/554?view=statement
int main() {
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq, pqRemove;
    unordered_set<int> removed;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int v;
            cin >> v;
            pq.push(v);
        } else if (type == 2) {
            int v;
            cin >> v;
            pqRemove.push(v);
            removed.insert(v);
        } else if (type == 3) {
            while (!pq.empty() && removed.count(pq.top())) {
                removed.erase(pq.top());
                pq.pop();
            }
            cout << pq.top() << endl;
        }
    }
    return 0;
}