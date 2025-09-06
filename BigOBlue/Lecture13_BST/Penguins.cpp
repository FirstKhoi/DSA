#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> penguins(n);
    for(int i = 0; i < n; i++) {
        getline(cin, penguins[i]);
    }
    unordered_map<string, int> freq;
    for(const string &count : penguins) {
        freq[count]++;
    }
    string most_common;
    int max_count = 0;
    for(const auto &pair : freq) {
        if(pair.second > max_count) {
            max_count = pair.second;
            most_common = pair.first;
        }
    }
    cout << most_common << endl;
    return 0;
}