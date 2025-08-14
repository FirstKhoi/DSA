#include<iostream>
#include<string>
#include<stack>
using namespace std;

void transform(string express) {
    stack<char> st;
    for(auto c : express) {
        if(isalpha(c)) {
            cout << c;
        }
        else if(c == ')') {
            cout << st.top();
            st.pop();
        } else if(c != '(') {
            st.push(c);   
        }
    }
    cout << endl;
}

int main() {
    int t; 
    string express;

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> express;
        transform(express);
    }
    return 0;
}