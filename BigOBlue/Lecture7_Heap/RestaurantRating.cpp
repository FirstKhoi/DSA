#include<iostream>
#include<queue>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3825/problems/560?view=statement
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x, type, nreviews = 0;
    priority_queue<int, vector<int>, greater<int>> top3; 
    priority_queue<int> rest;                            
    cin >> n;

    while (n--) {
        cin >> type;
    
        if (type == 1) {
            cin >> x;
            nreviews++;
            
            rest.push(x);

            if (top3.size() < nreviews/3 && !rest.empty()) {
                top3.push(rest.top());
                rest.pop();
            }

            if (nreviews >= 3 && !rest.empty() && !top3.empty() && rest.top() > top3.top()) {
                int restMax = rest.top();
                rest.pop();
                rest.push(top3.top());
                top3.pop();
                top3.push(restMax);
            }
            

            while (top3.size() > nreviews/3) {
                rest.push(top3.top());
                top3.pop();
            }
        }
        else {
            if (top3.empty()) {
                cout << "No reviews yet\n";
            } else {
                cout << top3.top() << '\n';
            }
        }
    }
    return 0;
}