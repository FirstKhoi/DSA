#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/merge-strings-alternately/description/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0, j = 0;
        while (i < word1.length() && j < word2.length()) {
            result += word1[i++];
            result += word2[j++];
        }
        while (i < word1.length()) {
            result += word1[i++];
        }
        while (j < word2.length()) {
            result += word2[j++];
        }
        return result;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    string word1 = "abc";
    string word2 = "pqr";
    string result = sol.mergeAlternately(word1, word2);
    cout << result << endl;
    return 0;
}