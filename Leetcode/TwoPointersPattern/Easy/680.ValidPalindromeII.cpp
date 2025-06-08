#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
// https://leetcode.com/problems/valid-palindrome-ii/
class Solution {
public:
    // avoid copying the string on each call by using a const reference
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }

    bool validPalindrome(const string& s) {
        int l = 0, r = int(s.size()) - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                // only two recursive checks, overall O(n) time
                return isPalindrome(s, l + 1, r) 
                    || isPalindrome(s, l, r - 1);
            }
            ++l; --r;
        }
        return true;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    Solution sol;

    // Example 1
    string s1 = "abca";
    bool result1 = sol.validPalindrome(s1);
    cout << "Example 1 Output: " << (result1 ? "true" : "false") << endl; // Expected: true

    // Example 2
    string s2 = "racecar";
    bool result2 = sol.validPalindrome(s2);
    cout << "Example 2 Output: " << (result2 ? "true" : "false") << endl; // Expected: true

    return 0;
}