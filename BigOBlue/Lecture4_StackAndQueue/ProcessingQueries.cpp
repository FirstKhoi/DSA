#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
    int n, b;
    long long t, d;
    long long process = 0;
    queue<long long> q;

    cin >> n >> b;
    for(int i = 0; i < n; i++) {
        cin >> t >> d;
        while(!q.empty() && q.front() <= t) {
            q.pop();
        }

        if(q.size() <= b) {
            process = max(process, t) + d;
            cout << process << " ";
            q.push(process);
        } else {
            cout << -1 << " ";
        }
    }

    return 0;
}