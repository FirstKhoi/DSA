#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    bool isPalindrome(const string& s) {
        int length = s.size();
        // Early return for single character strings
        if (length <= 1) return true;
        
        // Only need to check half of the string
        for (int i = 0; i < length / 2; ++i) {
            if (s[i] != s[length - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for (const auto& word : words) {
            // Skip empty strings
            if (word.empty()) continue;
            
            // Early return for single character words
            if (word.size() == 1) return word;
            
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    Solution sol;

    // Example 1
    vector<string> words1 = {"abc", "car", "ada", "racecar", "cool"};
    string result1 = sol.firstPalindrome(words1);
    cout << "Example 1 Output: " << (result1 != "" ? result1 : "No Palindrome Found") << endl;

    // Example 2
    vector<string> words2 = {"racecar" ,"notpalindrome"};
    string result2 = sol.firstPalindrome(words2);
    cout << "Example 2 Output: " << (result2 != "" ? result2 : "No Palindrome Found") << endl;

    return 0;
}