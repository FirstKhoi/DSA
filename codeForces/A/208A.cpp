#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    size_t pos;
    while ((pos = s.find("WUB")) != string::npos) {
        s.replace(pos, 3, " ");
    }
    
    bool space = false;
    for (char c : s) {
        if (c != ' ') {
            if (space) cout << " ";
            cout << c;
            space = false;
        } else {
            space = true;
        }
    }
    cout << '\n';
    return 0;
}