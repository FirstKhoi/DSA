#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/implement-stack-using-queues/?envType=problem-list-v2&envId=stack
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
        // No initialization needed
    }
    
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl;  // 2
    cout << obj->pop() << endl;   // 2
    cout << obj->empty() << endl; // 0
    return 0;
}
