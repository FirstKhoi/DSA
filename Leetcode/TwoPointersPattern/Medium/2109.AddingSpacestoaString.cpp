#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/adding-spaces-to-a-string/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        result.reserve(s.size() + spaces.size());
        
        int prev = 0;
        for (int space : spaces) {
            result.append(s, prev, space - prev);
            result.push_back(' ');
            prev = space;
        }
        
        if (prev < s.size()) {
            result.append(s, prev, s.size() - prev);
        }
        
        return result;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    cout << sol.addSpaces("LeetcodeHelpsMeLearn", {8, 13, 15}) << endl;  // Example test case
    return 0;
}