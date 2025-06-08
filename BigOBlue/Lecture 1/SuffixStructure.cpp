#include <iostream>
#include <vector>
#include <string>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3808/problems/1053?view=statement
bool isSubsequence(const string &s, const string &t) {
    int posS = 0, posT = 0;
    while (posS < s.size() && posT < t.size()) {
        if (s[posS] == t[posT]) {
            posT++;
        }   
        posS++;
    }
    return posT == t.size();
}

int main() {
    string s, t;
    cin >> s >> t;

    vector<int> countS(26, 0), countT(26, 0);
    for (char c : s) countS[c - 'a']++;
    for (char c : t) countT[c - 'a']++;

    for (int i = 0; i < 26; i++) {
        if (countT[i] > countS[i]) {
            cout << "need tree\n";
            return 0;
        }
    }

    if (isSubsequence(s, t)) {
        cout << "automaton\n";
        return 0;
    }

    if (countS == countT) {
        cout << "array\n";
        return 0;
    }

    cout << "both\n";
    return 0;
}

