#include <iostream>
#include <queue>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3825/problems/553?view=statement
int main() {
    int x, n;
    priority_queue<int> pq;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);

        if (i < 2) {
            cout << -1 << endl;
        }
        else {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int third = pq.top();
            pq.pop();

            cout << 1LL * first * second * third << endl;

            pq.push(first);
            pq.push(second);
            pq.push(third);
        }
    }
    return 0;
}