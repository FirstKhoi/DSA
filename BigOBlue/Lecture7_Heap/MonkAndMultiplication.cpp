#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    priority_queue<int> pq;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
        if(i < 2) cout << -1 << endl;  
        
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