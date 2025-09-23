#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    string expression;
    for(int i = 0; i < t; i++) {
        cin >> expression;
        stack<char> st;
        for(char &c : expression) {
            if(isalpha(c)) cout << c;
            else if(c == ')') {
                cout << st.top(); st.pop();
            } else if(c != '(') {
                st.push(c);
            }
        }
        cout << endl;
    }
    return 0;
}
