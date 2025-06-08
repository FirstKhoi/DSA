#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/implement-queue-using-stacks/?envType=problem-list-v2&envId=stack
class MyQueue {
private:
    stack<int> inStack;    
    stack<int> outStack;   
    void transferIfNeeded() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
    
public:
    MyQueue() {
        // No initialization needed
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        transferIfNeeded();
        int val = outStack.top();
        outStack.pop();
        return val;
    }
    
    int peek() {
        transferIfNeeded();
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    MyQueue* queue = new MyQueue();
    queue->push(1);
    queue->push(2);
    cout << queue->peek() << endl; // returns 1
    cout << queue->pop() << endl;  // returns 1
    cout << queue->empty() << endl; // returns false
    queue->push(3);
    cout << queue->peek() << endl; // returns 2
    cout << queue->pop() << endl;  // returns 2
    cout << queue->empty() << endl; // returns false
    cout << queue->pop() << endl;  // returns 3
    cout << queue->empty() << endl; // returns true
    delete queue; // Clean up memory
    return 0;
}