#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://leetcode.com/problems/check-if-n-and-its-double-exist/?envType=problem-list-v2&envId=2fh4qdsc
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        // Sort the array for two pointer technique
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            int target = 2 * arr[i];
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target && mid != i) {
                    return true;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    Solution sol;
    vector<int> arr = {10, 2, 5, 3};
    bool result = sol.checkIfExist(arr);
    cout << (result ? "true" : "false") << endl; //true
    
    return 0;
}