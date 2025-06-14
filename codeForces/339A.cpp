#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    string digits;
    for (char c : s)
        if (isdigit(c)) digits += c;
    sort(digits.begin(), digits.end());
    for (size_t i = 0; i < digits.size(); ++i) {
        if (i) cout << '+';
        cout << digits[i];
    }
    cout << '\n';
    return 0;
}
