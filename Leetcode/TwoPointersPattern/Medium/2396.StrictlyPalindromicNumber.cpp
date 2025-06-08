#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/strictly-palindromic-number/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int base = 2; base <= n - 2; ++base) {
            string converted = "";
            int temp = n;
            while (temp > 0) {
                converted = to_string(temp % base) + converted;
                temp /= base;
            }
            if (converted != string(converted.rbegin(), converted.rend())) {
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
    cout << sol.isStrictlyPalindromic(9) << endl;  // Example test case
    return 0;
}