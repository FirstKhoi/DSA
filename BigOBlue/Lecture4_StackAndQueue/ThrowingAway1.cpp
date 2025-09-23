#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    while (cin >> n && n) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) q.push(i);
        vector<int> discarded;
        while (q.size() > 1) {
            discarded.push_back(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << "Discarded cards:";
        if (!discarded.empty()) {
            cout << " ";
            for (size_t i = 0; i < discarded.size(); ++i) {
                cout << discarded[i];
                if (i + 1 < discarded.size()) cout << ", ";
            }
        }
        cout << "\nRemaining card: " << q.front() << '\n';
    }
    return 0;
}