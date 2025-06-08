#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;

int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    else if (op == '^') return 3;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string expression;
        cin >> expression;
        
        stack<char> operators;
        string result = "";
        
        for (char c : expression) {
            if (isalpha(c)) {
                result += c;
            } else if (c == '(') {
                operators.push(c);
            } else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    result += operators.top();
                    operators.pop();
                }
                if (!operators.empty()) operators.pop();
            } else {
                int priority;
                if (c == '+' || c == '-') priority = 1;
                else if (c == '*' || c == '/') priority = 2;
                else if (c == '^') priority = 3;
                else priority = 0;
                while (!operators.empty() && operators.top() != '(' && 
                      ((c != '^' && getPriority(operators.top()) >= priority) || 
                       (c == '^' && getPriority(operators.top()) > priority))) {
                    result += operators.top();
                    operators.pop();
                }
                operators.push(c);
            }
        }
        while (!operators.empty()) {
            result += operators.top();
            operators.pop();
        }
        cout << result << "\n";
    }
    return 0;
}