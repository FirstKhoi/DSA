#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq, remove;
    int Q; cin >> Q;

    int toDo, value;

    for(int i = 0; i < Q; i++) {
        cin >> toDo;

        if(toDo == 1) {
            cin >> value;
            pq.push(value);
        } else if(toDo == 2) {
            cin >> value;
            remove.push(value);
        } else {
            while(!remove.empty() && pq.top() == remove.top()) {
                pq.pop();
                remove.pop();
            }
            cout << pq.top() << endl;
        }
    }
    return 0;
}