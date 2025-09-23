#include <iostream>
#include <stack>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3816/problems/1063?view=statement

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        stack<char> st;
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '<') st.push('<');
            else {
                if(!st.empty() && st.top()== '<') {
                    st.pop();
                    if(st.empty()) res = i + 1;
                }   else break;
            }
        }
        cout << res << endl;
    }
    return 0;
}