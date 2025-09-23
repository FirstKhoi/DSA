#include<bits/stdc++.h>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3825/problems/1068?view=statement

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        
        bool could_be_stack = true;
        bool could_be_queue = true;
        bool could_be_pq = true;
        
        for (int i = 0; i < n; i++) {
            int op, x;
            cin >> op;
            if (op == 1) {
                cin >> x;
                
                s.push(x);
                q.push(x);
                pq.push(x);
            } else { 
                cin >> x; 

                if (!s.empty()) {
                    int top = s.top();
                    s.pop();
                    if (top != x) could_be_stack = false;
                } else {
                    could_be_stack = false;
                }

                if (!q.empty()) {
                    int front = q.front();
                    q.pop();
                    if (front != x) could_be_queue = false;
                } else {
                    could_be_queue = false;
                }
                

                if (!pq.empty()) {
                    int max = pq.top();
                    pq.pop();
                    if (max != x) could_be_pq = false;
                } else {
                    could_be_pq = false;
                }
            }
        }
        
        if (could_be_stack && !could_be_queue && !could_be_pq) {
            cout << "stack" << endl;
        } else if (!could_be_stack && could_be_queue && !could_be_pq) {
            cout << "queue" << endl;
        } else if (!could_be_stack && !could_be_queue && could_be_pq) {
            cout << "priority queue" << endl;
        } else if (could_be_stack || could_be_queue || could_be_pq) {
            cout << "not sure" << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    
    return 0;
}