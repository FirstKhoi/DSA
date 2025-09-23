#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    set<char> st;
    for (char c : s) {
        if (isalpha(c)) {
            st.insert(c);
        }
    }
    cout << st.size() << '\n';
    return 0;
}