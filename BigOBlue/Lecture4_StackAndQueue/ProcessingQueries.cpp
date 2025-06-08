#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, b; cin >> n >> b;
    vector<int> t(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> d[i];
    }
    queue<int> q; 
    vector<ll> finish(n, -1);
    ll curTime = 0; 

    for (int i = 0; i < n; ++i) {
        while (!q.empty() && curTime <= t[i]) {
            int idx = q.front(); q.pop();
            curTime = max(curTime, (ll)t[idx]) + d[idx];
            finish[idx] = curTime;
        }
        if (curTime <= t[i]) {
            curTime = (ll)t[i] + d[i];
            finish[i] = curTime;
        } else {
            if ((int)q.size() < b) {
                q.push(i); 
            } else {
                finish[i] = -1; 
            }
        }
    }
    while (!q.empty()) {
        int idx = q.front(); q.pop();
        curTime = max(curTime, (ll)t[idx]) + d[idx];
        finish[idx] = curTime;
    }
    for (int i = 0; i < n; ++i) {
        cout << finish[i] << " ";
    }
    cout << "\n";
    return 0;
}