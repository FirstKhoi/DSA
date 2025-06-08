#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        stack<int> side;
        int need = 1, i = 0;
        while (i < n || (!side.empty() && side.top() == need)) {
            if (!side.empty() && side.top() == need) {
                side.pop();
                ++need;
            } else if (i < n && a[i] == need) {
                ++i;
                ++need;
            } else if (i < n) {
                side.push(a[i]);
                ++i;
            } else {
                break;
            }
        }
        cout << (need == n + 1 ? "yes" : "no") << '\n';
    }
    return 0;
}git rm -r --cached .
git add .
git commit -m "Clean up ignored files"