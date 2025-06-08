#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/partition-labels/description/?envType=problem-list-v2&envId=two-pointers
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> result;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = sol.partitionLabels(s);
    for (int len : result) {
        cout << len << " ";
    }
    return 0;
}