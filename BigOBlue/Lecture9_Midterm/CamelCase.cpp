#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int wordCount = 1;
    for (char c : s) {
        if (isupper(c)) {
            wordCount++;
        }
    }
    cout << wordCount << '\n';
    return 0;
}