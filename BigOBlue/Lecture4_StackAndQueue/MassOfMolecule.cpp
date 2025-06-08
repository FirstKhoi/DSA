#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://bigocoder.com/courses/252/lectures/3816/problems/539?view=statement
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s; cin >> s;
    stack<int> st;
    for (char c : s) {
        if (c == 'H') st.push(1);
        else if (c == 'C') st.push(12);
        else if (c == 'O') st.push(16);
        else if (c == '(') st.push(-1); 
        else if (c == ')') {
            int sum = 0;
            while (!st.empty() && st.top() != -1) {
                sum += st.top();
                st.pop();
            }
            st.pop();
            st.push(sum);
        } else if (isdigit(c)) {
            int top = st.top(); st.pop();
            st.push(top * (c - '0'));
        }
    }
    int res = 0;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << res << '\n';
    return 0;
}