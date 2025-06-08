#include <bits/stdc++.h>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3816/problems/538?view=statement
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    while (true) {
        int P, C;
        cin >> P >> C;
        if (P == 0 && C == 0) break;
        cout << "Case " << tc++ << ":\n";
        deque<int> dq;
        int limit = min(P, 1000);
        for (int i = 1; i <= limit; ++i) dq.push_back(i);

        set<int> inQueue;
        for (int i = 1; i <= limit; ++i) inQueue.insert(i);

        for (int i = 0; i < C; ++i) {
            string cmd;
            cin >> cmd;
            if (cmd == "N") {
                int x = dq.front(); dq.pop_front();
                cout << x << '\n';
                dq.push_back(x);
            } else { // cmd == "E"
                int x;
                cin >> x;
                dq.erase(remove(dq.begin(), dq.end(), x), dq.end());
                dq.push_front(x);
            }
        }
    }
    return 0;
}