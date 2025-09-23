#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> cars(n);
        for(int i = 0; i < n; i++) {
            cin >> cars[i];
        }
        stack<int> st;
        int needed = 1, i = 0;
        while(i < n || (!st.empty() && st.top() == needed)) {
            if(!st.empty() && st.top() == needed) {
                st.pop();
                needed++;
            } else if(i < n && cars[i] == needed) {
                i++; needed++;
            } else if(i < n) {
                st.push(cars[i]);
                i++;
            } else break;
        }
        cout << (needed == i + 1 ? "yes" : "no") << endl;
    }
    return 0;
}