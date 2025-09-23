#include <bits/stdc++.h>
//https://codeforces.com/contest/382/problem/A
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, extra;
    cin >> s >> extra;

    int pos = s.find('|');
    int l = pos;
    int r = s.size() - pos - 1;
    int extra_size = extra.size();
    int total = l + r + extra_size;
    
    if (total % 2 != 0 || max(l, r) > total / 2) {
        cout << "Impossible\n";
        return 0;
    }

    int need_left = total / 2 - l;
    
    if (need_left < 0 || need_left > extra_size) {
        cout << "Impossible\n";
        return 0;
    }

    cout << s.substr(0, pos) << extra.substr(0, need_left) << "|" 
         << s.substr(pos + 1) << extra.substr(need_left) << "\n";
    return 0;
}
