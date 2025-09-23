#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
    set<int> s;
    int T, n, x, temp;
    cin >> T;
    while(T--) {
        s.clear();
        cin >> n >> x;
        
        for(int i = 0; i < n; i++) {
            cin >> temp;
            s.insert(temp);
        }

        int check = s.size();

        if(check == x) {
            cout << "Good" << endl;
        } else if(check < x) {
            cout << "Bad" << endl;
        } else {
            cout << "Average" << endl;
        }
    }

    
}