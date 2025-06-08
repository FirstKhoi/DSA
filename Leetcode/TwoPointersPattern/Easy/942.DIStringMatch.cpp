#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/di-string-match/description/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> result(n + 1);
        int low = 0, high = n;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'I'){
                result[i] = low++;
            } else {
                result[i] = high--;
            }
        }
        result[n] = low;
        return result;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    string s = "IDID";
    vector<int> result = sol.diStringMatch(s);
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
