#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
using ll = long long;
//https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/?envType=problem-list-v2&envId=string
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        int firstFreq = freq.begin()->second;
        
        for (const auto& entry : freq) {
            if (entry.second != firstFreq) {
                return false;
            }
        }
        
        return true;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    cout << sol.areOccurrencesEqual("abacbc") << endl;  // Output: 1 (true)
    cout << sol.areOccurrencesEqual("aaabb") << endl;   // Output: 0 (false)
    return 0;
}